#ifndef FFMPEGDECODE_H
#define FFMPEGDECODE_H

#include <QString>
#include "sdlplayer.h"

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavutil/ffversion.h"
#include "libavformat/avformat.h"
#include "libswresample/swresample.h"
}

struct AudioDecode
{
    AVFormatContext*    avFmtCtx;
    AVCodecContext*     avCodecCtx;
    AVPacket*           avPacket;
    AVFrame*            avFrame;
    AVCodec*            avCodec;
};

class FFMpegDecode
{
public:
    FFMpegDecode();
    ~FFMpegDecode();

private:
    void AVAlloc();
    void AVFree();

public:
    bool OpenMusicFile(char* fileName);
    void SetSDLPlayer(SDLPlayer*  pSDLPlayer);

private:
    AudioDecode m_audioDecode;
    SDLPlayer*  m_pSDLPlayer;
};

#endif // FFMPEGDECODE_H
