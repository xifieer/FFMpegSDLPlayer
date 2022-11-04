#include "ffmpegdecode.h"
#include <QDebug>

FFMpegDecode::FFMpegDecode()
{
    m_audioDecode.avFmtCtx      = nullptr;
    m_audioDecode.avCodecCtx    = nullptr;
    m_audioDecode.avPacket      = nullptr;
    m_audioDecode.avFrame       = nullptr;
    m_audioDecode.avCodec       = nullptr;
    m_pSDLPlayer                = nullptr;
}

FFMpegDecode::~FFMpegDecode()
{
    AVFree();
}

void FFMpegDecode::AVAlloc()
{
    if(m_audioDecode.avFmtCtx == nullptr)
    {
        m_audioDecode.avFmtCtx = avformat_alloc_context();
    }

    if(m_audioDecode.avPacket == nullptr)
    {
        m_audioDecode.avPacket = av_packet_alloc();
    }

    if(m_audioDecode.avFrame == nullptr)
    {
       m_audioDecode.avFrame   = av_frame_alloc();
    }
}

void FFMpegDecode::AVFree()
{
    if(m_audioDecode.avFmtCtx)
    {
        avformat_free_context(m_audioDecode.avFmtCtx);
        m_audioDecode.avFmtCtx = nullptr;
    }

    if(m_audioDecode.avPacket)
    {
        av_packet_free(&m_audioDecode.avPacket);
        m_audioDecode.avPacket = nullptr;
    }

    if(m_audioDecode.avFrame)
    {
        av_frame_free(&m_audioDecode.avFrame);
        m_audioDecode.avFrame = nullptr;
    }

    if(m_audioDecode.avCodecCtx)
    {
        avcodec_close(m_audioDecode.avCodecCtx);
        avcodec_free_context(&m_audioDecode.avCodecCtx);
        m_audioDecode.avCodecCtx = nullptr;
    }
}

bool FFMpegDecode::OpenMusicFile(char* fileName)
{
    if(fileName == nullptr || m_pSDLPlayer == nullptr) return false;

    int ret;
    AVAlloc();

    // 打开文件
    if ((ret = avformat_open_input(&m_audioDecode.avFmtCtx, fileName, NULL, NULL)) < 0)
    {
        printf("avformat_open_input error");
        AVFree();
        return false;
    }

    // 获取流信息
    if ((ret = avformat_find_stream_info(m_audioDecode.avFmtCtx, NULL)) < 0)
    {
        printf("avformat_find_stream_info error");
        AVFree();
        return false;
    }

    // 获取输入音乐文件的音频流
    if ((ret = av_find_best_stream(m_audioDecode.avFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, (const AVCodec **)&m_audioDecode.avCodec, 0)) < 0)
    {
        printf("av_find_best_stream error");
        AVFree();
        return false;
    }
    int audio_stream_index = ret;

    // 获取解码器参数
    AVCodecParameters *avCodecParameters = m_audioDecode.avFmtCtx->streams[audio_stream_index]->codecpar;

    // 解码器上下文
    m_audioDecode.avCodecCtx = avcodec_alloc_context3(m_audioDecode.avCodec);
    if(m_audioDecode.avCodecCtx == nullptr)
    {
        printf("av_find_best_stream error");
        AVFree();
        return false;
    }

    // 将解码器参数给解码器上下文
    if ((ret = avcodec_parameters_to_context(m_audioDecode.avCodecCtx, avCodecParameters)) < 0)
    {
        printf("avcodec_parameters_to_context error");
        AVFree();
        return false;
    }

    // 打开解码器
    if(avcodec_open2(m_audioDecode.avCodecCtx, m_audioDecode.avCodec, NULL) < 0)
    {
        printf("avcodec_open2 error");
        AVFree();
        return false;
    }

    // 转换器上下文
    SwrContext *swrContext = swr_alloc();
    // 输入文件的参数
    // 获取输入采样位数
    AVSampleFormat in_sample_fmt = m_audioDecode.avCodecCtx->sample_fmt;
    // 获取输入采样率
    int in_sample_rate = m_audioDecode.avCodecCtx->sample_rate;
    // 获取输入通道数
    AVChannelLayout in_channel_layout = m_audioDecode.avCodecCtx->ch_layout;
    //输出参数
    //定义输出采样位数
    AVSampleFormat out_sample_fmt = AV_SAMPLE_FMT_S16;
    //定义输出采样率
    int out_sample_rate = 44100;
    //定义输出通道
    AVChannelLayout out_channel_layout = AV_CHANNEL_LAYOUT_STEREO;

    //设置重采样频率,采样位数,通道数
    ret = swr_alloc_set_opts2(&swrContext, &out_channel_layout, out_sample_fmt, out_sample_rate,
                                           &in_channel_layout, in_sample_fmt, in_sample_rate, 0, NULL);
    if (ret < 0)
    {
        printf("swr_alloc_set_opts2 error");
        AVFree();
        return false;
    }

    //初始化转换器
    swr_init(swrContext);
    //设置输出缓冲区,大小一般为输出采样率*通道数,上面用的是双通道
    uint8_t *out_buffer = (uint8_t *) (av_malloc(2 * 44100));

    //打开音频文件解压为wb格式
    FILE *fc_pcm = fopen("d:/12.pcm", "wb");

    bool hadStart = false;
    //读取音频流
    while (av_read_frame(m_audioDecode.avFmtCtx, m_audioDecode.avPacket) >= 0)
    {
        avcodec_send_packet(m_audioDecode.avCodecCtx, m_audioDecode.avPacket);
        //拿到解码后的数据(未压缩数据)
        int result = avcodec_receive_frame(m_audioDecode.avCodecCtx, m_audioDecode.avFrame);
        if (result == AVERROR(EAGAIN)) // 有错误
        {
            continue;
        }
        else if (result < 0) //解码完成
        {
            break;
        }

        if (m_audioDecode.avPacket->stream_index != audio_stream_index) //判断是否是音频流
        {
            continue;
        }

        //将解压后的frame重采样转换成统一格式
        int out_len = swr_convert(swrContext, &out_buffer, 2 * 44100, (const uint8_t **) (m_audioDecode.avFrame->data), m_audioDecode.avFrame->nb_samples);

        //out_buffer输出到文件
        //获取输出的布局通道数
        int out_nb_channel = out_channel_layout.nb_channels;
        //获取每一帧的实际大小
        int out_buffer_size = av_samples_get_buffer_size(NULL, out_nb_channel, m_audioDecode.avFrame->nb_samples, out_sample_fmt, 1);

        //写入文件
        fwrite(out_buffer, 1, out_buffer_size, fc_pcm);

        m_pSDLPlayer->AddPcmData(out_buffer, out_buffer_size);

        if(hadStart == false)
        {
           m_pSDLPlayer->Start();
           hadStart = true;
        }
    }

    fclose(fc_pcm);
    AVFree();
}

void FFMpegDecode::SetSDLPlayer(SDLPlayer*  pSDLPlayer)
{
    m_pSDLPlayer = pSDLPlayer;
}
