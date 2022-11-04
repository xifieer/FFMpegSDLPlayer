#include "sdlplayer.h"
#include "stdio.h"

SDLPlayer::SDLPlayer()
{
    /* 音频初始化 */
    m_wantAudioSpec.freq = 44100;                 // 44100赫兹
    m_wantAudioSpec.format = AUDIO_S16SYS;        // 16位精度
    m_wantAudioSpec.channels = 2;                 // 双声道
    m_wantAudioSpec.silence = 0;                  // 设置静音的值
    m_wantAudioSpec.samples = 1024;               // 每帧大小
    m_wantAudioSpec.userdata = this;              // 用户输入参数
#if PULL_MODEL
    m_wantAudioSpec.callback = PlayAudioCallback; // 拉模式回调函数
#else
    m_wantAudioSpec.callback = NULL;              // 推模式
#endif

    m_pDecodeRingBuffer = nullptr;

    // 初始化音频播放
    int ret = SDL_Init(SDL_INIT_AUDIO);
    if(ret < 0)
    {
        printf("error: SDL_Init\n");
        return;
    }

    // 获取音频播放设备数
    int num = SDL_GetNumAudioDevices(0);
    if(num <= 0)
    {
        printf("error: SDL_GetNumAudioDevices\n");
        return;
    }

    // 获取音频设备名称
    const char* deviceName = SDL_GetAudioDeviceName(0, 0);

    // 打开音频播放设备
    m_audioDeviceID = SDL_OpenAudioDevice(deviceName, SDL_FALSE, &m_wantAudioSpec, NULL, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);
    if (m_audioDeviceID < 2)
    {
        printf("error: SDL_OpenAudioDevice %s\n", SDL_GetError());
        return;
    }

    // 申请播放缓存
    m_pDecodeRingBuffer = RingBuffer_Malloc(1024 * 1024 * 80);
}

// 启动播放
void SDLPlayer::Start()
{
    SDL_PauseAudioDevice(m_audioDeviceID, SDL_FALSE);
}

// 停止播放
void SDLPlayer::Stop()
{
    SDL_PauseAudioDevice(m_audioDeviceID, SDL_TRUE);
}

// 添加PCM数据到播放缓存
void SDLPlayer::AddPcmData(unsigned char* data, int len)
{
    if(m_pDecodeRingBuffer == nullptr) return;

#if PULL_MODEL
    RingBuffer_In(m_pDecodeRingBuffer, data, len);
#else
    SDL_QueueAudio(m_audioDeviceID, data, len);
#endif
}

// 拉流模式回调函数
void SDLPlayer::PlayAudioCallback(void *udata, Uint8 *stream, int len)
{
    if(udata == nullptr) return;

    SDLPlayer* pThis = (SDLPlayer*)udata;

    if(pThis->m_pDecodeRingBuffer == nullptr) return;

    // 把PCM数据读到SDL播放缓存里
    int readLen = RingBuffer_Out(pThis->m_pDecodeRingBuffer, stream, len);

    if(readLen <= 0) // 音频数据播放完毕
    {
        pThis->Stop();
    }
}
