#include <mp4v2/mp4v2.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <x264.h>
#include <mp4v2/mp4v2.h>

#define WIDTH 640
#define HEIGHT 480

using namespace std;

int main()
{
    // Create a mp4 file
    MP4FileHandle mp4File = MP4Create("random_content.mp4", 0);

    // Create the video track
    MP4TrackId videoTrack = MP4AddH264VideoTrack(mp4File, 25, 90000, WIDTH, HEIGHT, 0x64, 0x00, 0x00, 0x00);

    // Configure the video track
    MP4SetVideoProfileLevel(mp4File, 0x7f);

    // Create the audio track
    MP4TrackId audioTrack = MP4AddAudioTrack(mp4File, 8000, 1024, MP4_MPEG4_AUDIO_TYPE);

    // Configure the audio track
    MP4SetAudioProfileLevel(mp4File, 0x2);

    // Create the encoder
    x264_param_t param;
    x264_param_default_preset(&param, "medium", "zerolatency");
    param.i_width = WIDTH;
    param.i_height = HEIGHT;
    param.i_csp = X264_CSP_I420;
    param.b_vfr_input = 0;
    param.b_repeat_headers = 1;
    param.b_annexb = 1;

    int iNal   = 0;
    x264_nal_t* pNals = NULL;
    x264_t *encoder = x264_encoder_open(&param);

    // Create a frame
    x264_picture_t pic_in, pic_out;
    x264_picture_init(&pic_out);
    x264_picture_alloc(&pic_in, param.i_csp, param.i_width, param.i_height);

    // Generate random content
    for (int i = 0; i < 100; i++)
    {
        // Generate a random image
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                pic_in.img.plane[0][y * WIDTH + x] = rand() % 256;
                pic_in.img.plane[1][(y / 2) * (WIDTH / 2) + (x / 2)] = rand() % 256;
                pic_in.img.plane[2][(y / 2) * (WIDTH / 2) + (x / 2)] = rand() % 256;
            }
        }

        // Encode the frame
        x264_nal_t *nals;
        int frame_size = x264_encoder_encode(encoder, &nals, &iNal, &pic_in, &pic_out);

        MP4WriteSample(mp4File, videoTrack, nals[0].p_payload, nals[0].i_payload, MP4_INVALID_DURATION, 0, 1);

        // Generate random audio
        unsigned char audio_data[1024];
        for (int j = 0; j < 1024; j++)
        {
            audio_data[j] = rand() % 256;
        }

        // Write the audio packet
        MP4WriteSample(mp4File, audioTrack, audio_data, 1024, MP4_INVALID_DURATION, 0, 1);
    }

    // Close the encoder
    x264_encoder_close(encoder);

    // Close the file
    MP4Close(mp4File, 0);
    return 0;
}