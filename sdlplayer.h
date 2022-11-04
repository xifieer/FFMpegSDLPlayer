#ifndef SDLPLAYER_H
#define SDLPLAYER_H

#include "SDL2/SDL.h"
#include "RingBuffer.h"

#define PULL_MODEL 0

class SDLPlayer
{
public:
    SDLPlayer();

public:
    void Init();
    void Start();
    void Stop();
    void AddPcmData(unsigned char* data, int len);

private:
    static void PlayAudioCallback(void *udata, Uint8 *stream, int len);

private:
    SDL_AudioDeviceID m_audioDeviceID;
    SDL_AudioSpec m_wantAudioSpec;
    RingBuffer* m_pDecodeRingBuffer;

};

#endif // SDLPLAYER_H
