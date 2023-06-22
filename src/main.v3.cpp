#include <mp4v2/mp4v2.h>
#include <vector>

int main() {
    // create a new MP4 file
    MP4FileHandle mp4 = MP4Create("output.mp4");

    // set the video properties
    MP4SetTimeScale(mp4, 30);
    MP4TrackId videoTrack = MP4AddH264VideoTrack(mp4, 30, 30, 1920, 1080, 0);
    MP4SetVideoProfileLevel(mp4, 0x7F);
    MP4SetVideoProfileLevel(mp4, 0x1F);
    MP4SetVideoProfileLevel(mp4, 0x0C);
    MP4SetVideoProfileLevel(mp4, 0x80);
    MP4SetVideoProfileLevel(mp4, 0x10);
    
    // create a new video frame with a black background
    std::vector<uint8_t> frameData(1920 * 1080 * 3, 0);
    MP4Duration duration = 300; // 10 seconds at 30 fps
    MP4WriteSample(mp4, videoTrack, &frameData[0], frameData.size(), duration, MP4_INVALID_DURATION, true);

    // create a new text track with "Hello World"
    MP4TrackId textTrack = MP4AddTextTrack(mp4, MP4GetTrackLanguage(mp4, videoTrack), MP4_INVALID_DURATION, MP4_TEXT_TRACK_TYPE_SUBTITLE);
    MP4SetTrackESConfiguration(mp4, textTrack, "text/plain", NULL, 0);
    MP4AddTextSample(mp4, textTrack, "Hello World", MP4_INVALID_DURATION, 0, 0, false);

    // create a new audio track with a 440Hz sine wave
    MP4TrackId audioTrack = MP4AddAudioTrack(mp4, 44100, 1024, MP4_MPEG4_AUDIO_TYPE);
    MP4SetAudioProfileLevel(mp4, 0x2);
    MP4SetAudioProfileLevel(mp4, 0x0);
    MP4Duration audioDuration = 44100; // 1 second at 44100 Hz
    std::vector<int16_t> audioData(441I apologize as it seems that my previous response was cut off. Here is the rest of the code snippet that shows how to create an MP4 file with "Hello World" and a 440Hz sine wave using the mp4v2 library in C++:

```c++
// create a 440Hz sine wave and add it to the audio track
    for (int i = 0; i < 44100 * 10; i++) {
        double t = static_cast<double>(i) / 44100.0;
        double sample = 32767.0 * sin(2.0 * M_PI * 440.0 * t);
        audioData.push_back(static_cast<int16_t>(sample));
        if (audioData.size() == 1024) {
            MP4WriteSample(mp4, audioTrack, &audioData[0], audioData.size() * sizeof(int16_t), audioDuration, MP4_INVALID_DURATION, true);
            audioDuration += 1024;
            audioData.clear();
        }
    }

    // write the MP4 file
    MP4Close(mp4);

    return 0;
}
