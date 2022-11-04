QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RingBuffer.c \
    ffmpegdecode.cpp \
    main.cpp \
    sdlplayer.cpp \
    widget.cpp

INCLUDEPATH +="./include"

HEADERS += \
    RingBuffer.h \
    ffmpegdecode.h \
    include/SDL2/SDL.h \
    include/SDL2/SDL_assert.h \
    include/SDL2/SDL_atomic.h \
    include/SDL2/SDL_audio.h \
    include/SDL2/SDL_bits.h \
    include/SDL2/SDL_blendmode.h \
    include/SDL2/SDL_clipboard.h \
    include/SDL2/SDL_config.h \
    include/SDL2/SDL_config.h.in \
    include/SDL2/SDL_config_android.h \
    include/SDL2/SDL_config_iphoneos.h \
    include/SDL2/SDL_config_macosx.h \
    include/SDL2/SDL_config_macosx.h.orig \
    include/SDL2/SDL_config_minimal.h \
    include/SDL2/SDL_config_pandora.h \
    include/SDL2/SDL_config_psp.h \
    include/SDL2/SDL_config_windows.h \
    include/SDL2/SDL_config_winrt.h \
    include/SDL2/SDL_config_wiz.h \
    include/SDL2/SDL_copying.h \
    include/SDL2/SDL_cpuinfo.h \
    include/SDL2/SDL_egl.h \
    include/SDL2/SDL_endian.h \
    include/SDL2/SDL_error.h \
    include/SDL2/SDL_events.h \
    include/SDL2/SDL_filesystem.h \
    include/SDL2/SDL_gamecontroller.h \
    include/SDL2/SDL_gesture.h \
    include/SDL2/SDL_guid.h \
    include/SDL2/SDL_haptic.h \
    include/SDL2/SDL_hidapi.h \
    include/SDL2/SDL_hints.h \
    include/SDL2/SDL_joystick.h \
    include/SDL2/SDL_keyboard.h \
    include/SDL2/SDL_keycode.h \
    include/SDL2/SDL_loadso.h \
    include/SDL2/SDL_locale.h \
    include/SDL2/SDL_log.h \
    include/SDL2/SDL_main.h \
    include/SDL2/SDL_messagebox.h \
    include/SDL2/SDL_metal.h \
    include/SDL2/SDL_misc.h \
    include/SDL2/SDL_mouse.h \
    include/SDL2/SDL_mutex.h \
    include/SDL2/SDL_name.h \
    include/SDL2/SDL_opengl.h \
    include/SDL2/SDL_opengl_glext.h \
    include/SDL2/SDL_opengles.h \
    include/SDL2/SDL_opengles2.h \
    include/SDL2/SDL_opengles2_gl2.h \
    include/SDL2/SDL_opengles2_gl2ext.h \
    include/SDL2/SDL_opengles2_gl2platform.h \
    include/SDL2/SDL_opengles2_khrplatform.h \
    include/SDL2/SDL_pixels.h \
    include/SDL2/SDL_platform.h \
    include/SDL2/SDL_power.h \
    include/SDL2/SDL_quit.h \
    include/SDL2/SDL_rect.h \
    include/SDL2/SDL_render.h \
    include/SDL2/SDL_revision.h \
    include/SDL2/SDL_rwops.h \
    include/SDL2/SDL_scancode.h \
    include/SDL2/SDL_sensor.h \
    include/SDL2/SDL_shape.h \
    include/SDL2/SDL_stdinc.h \
    include/SDL2/SDL_surface.h \
    include/SDL2/SDL_system.h \
    include/SDL2/SDL_syswm.h \
    include/SDL2/SDL_test.h \
    include/SDL2/SDL_test_assert.h \
    include/SDL2/SDL_test_common.h \
    include/SDL2/SDL_test_compare.h \
    include/SDL2/SDL_test_crc32.h \
    include/SDL2/SDL_test_font.h \
    include/SDL2/SDL_test_fuzzer.h \
    include/SDL2/SDL_test_harness.h \
    include/SDL2/SDL_test_images.h \
    include/SDL2/SDL_test_log.h \
    include/SDL2/SDL_test_md5.h \
    include/SDL2/SDL_test_memory.h \
    include/SDL2/SDL_test_random.h \
    include/SDL2/SDL_thread.h \
    include/SDL2/SDL_timer.h \
    include/SDL2/SDL_touch.h \
    include/SDL2/SDL_types.h \
    include/SDL2/SDL_version.h \
    include/SDL2/SDL_video.h \
    include/SDL2/SDL_vulkan.h \
    include/SDL2/begin_code.h \
    include/SDL2/close_code.h \
    include/libavcodec/ac3_parser.h \
    include/libavcodec/adts_parser.h \
    include/libavcodec/avcodec.h \
    include/libavcodec/avdct.h \
    include/libavcodec/avfft.h \
    include/libavcodec/bsf.h \
    include/libavcodec/codec.h \
    include/libavcodec/codec_desc.h \
    include/libavcodec/codec_id.h \
    include/libavcodec/codec_par.h \
    include/libavcodec/d3d11va.h \
    include/libavcodec/defs.h \
    include/libavcodec/dirac.h \
    include/libavcodec/dv_profile.h \
    include/libavcodec/dxva2.h \
    include/libavcodec/jni.h \
    include/libavcodec/mediacodec.h \
    include/libavcodec/packet.h \
    include/libavcodec/qsv.h \
    include/libavcodec/vdpau.h \
    include/libavcodec/version.h \
    include/libavcodec/version_major.h \
    include/libavcodec/videotoolbox.h \
    include/libavcodec/vorbis_parser.h \
    include/libavcodec/xvmc.h \
    include/libavdevice/avdevice.h \
    include/libavdevice/version.h \
    include/libavdevice/version_major.h \
    include/libavfilter/avfilter.h \
    include/libavfilter/buffersink.h \
    include/libavfilter/buffersrc.h \
    include/libavfilter/version.h \
    include/libavfilter/version_major.h \
    include/libavformat/avformat.h \
    include/libavformat/avio.h \
    include/libavformat/version.h \
    include/libavformat/version_major.h \
    include/libavutil/adler32.h \
    include/libavutil/aes.h \
    include/libavutil/aes_ctr.h \
    include/libavutil/attributes.h \
    include/libavutil/audio_fifo.h \
    include/libavutil/avassert.h \
    include/libavutil/avconfig.h \
    include/libavutil/avstring.h \
    include/libavutil/avutil.h \
    include/libavutil/base64.h \
    include/libavutil/blowfish.h \
    include/libavutil/bprint.h \
    include/libavutil/bswap.h \
    include/libavutil/buffer.h \
    include/libavutil/camellia.h \
    include/libavutil/cast5.h \
    include/libavutil/channel_layout.h \
    include/libavutil/common.h \
    include/libavutil/cpu.h \
    include/libavutil/crc.h \
    include/libavutil/csp.h \
    include/libavutil/des.h \
    include/libavutil/detection_bbox.h \
    include/libavutil/dict.h \
    include/libavutil/display.h \
    include/libavutil/dovi_meta.h \
    include/libavutil/downmix_info.h \
    include/libavutil/encryption_info.h \
    include/libavutil/error.h \
    include/libavutil/eval.h \
    include/libavutil/ffversion.h \
    include/libavutil/fifo.h \
    include/libavutil/file.h \
    include/libavutil/film_grain_params.h \
    include/libavutil/frame.h \
    include/libavutil/hash.h \
    include/libavutil/hdr_dynamic_metadata.h \
    include/libavutil/hdr_dynamic_vivid_metadata.h \
    include/libavutil/hmac.h \
    include/libavutil/hwcontext.h \
    include/libavutil/hwcontext_cuda.h \
    include/libavutil/hwcontext_d3d11va.h \
    include/libavutil/hwcontext_drm.h \
    include/libavutil/hwcontext_dxva2.h \
    include/libavutil/hwcontext_mediacodec.h \
    include/libavutil/hwcontext_opencl.h \
    include/libavutil/hwcontext_qsv.h \
    include/libavutil/hwcontext_vaapi.h \
    include/libavutil/hwcontext_vdpau.h \
    include/libavutil/hwcontext_videotoolbox.h \
    include/libavutil/hwcontext_vulkan.h \
    include/libavutil/imgutils.h \
    include/libavutil/intfloat.h \
    include/libavutil/intreadwrite.h \
    include/libavutil/lfg.h \
    include/libavutil/log.h \
    include/libavutil/lzo.h \
    include/libavutil/macros.h \
    include/libavutil/mastering_display_metadata.h \
    include/libavutil/mathematics.h \
    include/libavutil/md5.h \
    include/libavutil/mem.h \
    include/libavutil/motion_vector.h \
    include/libavutil/murmur3.h \
    include/libavutil/opt.h \
    include/libavutil/parseutils.h \
    include/libavutil/pixdesc.h \
    include/libavutil/pixelutils.h \
    include/libavutil/pixfmt.h \
    include/libavutil/random_seed.h \
    include/libavutil/rational.h \
    include/libavutil/rc4.h \
    include/libavutil/replaygain.h \
    include/libavutil/ripemd.h \
    include/libavutil/samplefmt.h \
    include/libavutil/sha.h \
    include/libavutil/sha512.h \
    include/libavutil/spherical.h \
    include/libavutil/stereo3d.h \
    include/libavutil/tea.h \
    include/libavutil/threadmessage.h \
    include/libavutil/time.h \
    include/libavutil/timecode.h \
    include/libavutil/timestamp.h \
    include/libavutil/tree.h \
    include/libavutil/twofish.h \
    include/libavutil/tx.h \
    include/libavutil/uuid.h \
    include/libavutil/version.h \
    include/libavutil/video_enc_params.h \
    include/libavutil/xtea.h \
    include/libpostproc/postprocess.h \
    include/libpostproc/version.h \
    include/libpostproc/version_major.h \
    include/libswresample/swresample.h \
    include/libswresample/version.h \
    include/libswresample/version_major.h \
    include/libswscale/swscale.h \
    include/libswscale/version.h \
    include/libswscale/version_major.h \
    sdlplayer.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L$$PWD/lib/ -lavcodec
LIBS += -L$$PWD/lib/ -lavdevice
LIBS += -L$$PWD/lib/ -lavfilter
LIBS += -L$$PWD/lib/ -lavformat
LIBS += -L$$PWD/lib/ -lavutil
LIBS += -L$$PWD/lib/ -lswresample
LIBS += -L$$PWD/lib/ -lswscale
LIBS += -L$$PWD/lib/ -lSDL2

DISTFILES += \
    include/SDL2/SDL_config.h.cmake

DESTDIR += $$PWD/bin/
