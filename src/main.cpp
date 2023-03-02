// #include <mp4v2/mp4v2.h>
// #include <iostream>

// // static bool convertBase64 (const char data, uint8_t *value)
// // {
// //     static const uint8_t decodingarr64[128] = {
// //         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
// //         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
// //         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
// //         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
// //         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
// //         0xff, 0xff, 0xff, 0x3e, 0xff, 0xff, 0xff, 0x3f,
// //         0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b,
// //         0x3c, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
// //         0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
// //         0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
// //         0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
// //         0x17, 0x18, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff,
// //         0xff, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20,
// //         0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
// //         0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30,
// //         0x31, 0x32, 0x33, 0xff, 0xff, 0xff, 0xff, 0xff,
// //     };
// //     uint8_t index = (uint8_t)data;
// //     if ((index & 0x80) != 0) return false;

// //     if (decodingarr64[index] == 0xff) return false;
// //     *value = decodingarr64[index];
// //     return true;
// // }

// // uint8_t *Base64ToBinary (const char *pData, uint32_t decodeSize, uint32_t *pDataSize)
// // {
// //     uint8_t *ret;
// //     uint32_t size, ix, groups;
// //     if (pData == NULL ||  decodeSize == 0 || pDataSize == NULL)
// //         return NULL;

// //     if ((decodeSize % 4) != 0) {
// //         // must be multiples of 4 characters
// //         return NULL;
// //     }
// //     size = (decodeSize * 3) / 4;
// //     groups = decodeSize / 4;
// //     ret = (uint8_t *)calloc(1, size);
// //     if (ret == NULL) return NULL;
// //     for (ix = 0; ix < groups; ix++) {
// //         uint8_t value[4];
// //         for (uint8_t jx = 0; jx < 4; jx++) {
// //             if (pData[jx] == '=') {
// //                 if (ix != (groups - 1)) {
// //                     free(ret);
// //                     return NULL;
// //                 }
// //                 size--;
// //                 value[jx] = 0;
// //             } else if (convertBase64(pData[jx], &value[jx]) == false) {
// //                 free(ret);
// //                 return NULL;
// //             }
// //         }
// //         ret[(ix * 3)] = value[0] << 2 | ((value[1] >> 4) & 0x3);
// //         ret[(ix * 3) + 1] = (value[1] << 4) | (value[2] >> 2 & 0xf);
// //         ret[(ix * 3) + 2] = ((value[2] & 0x3) << 6) | value[3];
// //         pData += 4;
// //     }
// //     *pDataSize = size;
// //     return ret;
// // }

// int main(int argc, char** argv)
// {
// // #if 1
//     MP4LogSetLevel(MP4_LOG_VERBOSE4);
//     MP4FileHandle mp4File = MP4Create("hahaha.mp4");
//     if (!mp4File) {
// 		std::cout << "Cannot create mp4 file" << std::endl;
// 		return 1;
// 	}

// 	if( mp4File == MP4_INVALID_FILE_HANDLE ) {
// 		std::cout << "MP4_INVALID_FILE_HANDLE" << std::endl;
// 		return 1;
// 	}

//     std::cout << "Created skeleton" << std::endl;

//     MP4Dump(mp4File);

//     MP4SetODProfileLevel(mp4File, 1);
//     MP4SetSceneProfileLevel(mp4File, 1);
//     MP4SetVideoProfileLevel(mp4File, 1);
//     MP4SetAudioProfileLevel(mp4File, 1);
//     MP4SetGraphicsProfileLevel(mp4File, 1);

//     MP4TrackId odTrackId = MP4AddODTrack(mp4File);

//     MP4TrackId bifsTrackId = MP4AddSceneTrack(mp4File);

//     MP4TrackId videoTrackId =
// // #if 0
// //     MP4AddVideoTrack(mp4File, 90000, 3000, 320, 240);
// // #else
//     MP4AddH264VideoTrack(mp4File, 90000, 3000, 320, 240, 1, 2, 3, 1);
//     static uint8_t pseq[] = { 0, 1, 2, 3, 4, 5, 6,7, 8, 9 };

//     MP4AddH264SequenceParameterSet(mp4File, videoTrackId, pseq, 10);
//     MP4AddH264SequenceParameterSet(mp4File, videoTrackId, pseq, 6);
//     MP4AddH264PictureParameterSet(mp4File, videoTrackId, pseq, 7);
//     MP4AddH264PictureParameterSet(mp4File, videoTrackId, pseq, 8);
//     MP4AddH264PictureParameterSet(mp4File, videoTrackId, pseq, 7);

// // #endif

//     MP4TrackId videoHintTrackId = MP4AddHintTrack(mp4File, videoTrackId);

//     MP4TrackId audioTrackId = MP4AddAudioTrack(mp4File, 44100, 1152);

//     MP4TrackId audioHintTrackId = MP4AddHintTrack(mp4File, audioTrackId);

// 	std::cout << "Added tracks" << std::endl;

//     MP4Dump(mp4File);
//     MP4Close(mp4File);

//     // MP4MakeIsmaCompliant(argv[1], verbosity);

//     return 0;

// // #else
// //    uint8_t *bin = NULL;
// //    for (uint32_t ix = 4; ix < 1024; ix++) {
// //      printf("pass %d\n", ix);
// //      bin = (uint8_t *)malloc(ix);
// //      for (uint32_t jx = 0; jx < ix; jx++) {
// //        bin[jx] = ((uint32_t)rand()) & 0xFF;
// //      }
// //      char *test;
// //      test = MP4BinaryToBase64(bin, ix);
// //      uint8_t *ret;
// //      uint32_t retsize;
// //      ret = Base64ToBinary(test, strlen(test), &retsize);
// //      if (retsize != ix) {
// //        printf("return size not same %d %d\n", ix, retsize);
// //        return 0;
// //      }
// //      if (memcmp(ret, bin, ix) != 0) {
// //        printf("memory not same\n");
// //        return 0;
// //      }
// //      free(test);
// //      free(ret);
// //      free(bin);
// //    }
// //    return 0;
// // #endif
// }

#include <iostream>
#include <fstream>

#include <mp4v2/mp4v2.h>

using namespace std;

class Mp4Encoder
{
public:
	Mp4Encoder();
	~Mp4Encoder();

	void Start(const char *filename, int width, int height,
			   int vtimescale = 90000, int framerate = 25, int atimescale = 48000);
	void Stop();

	int WriteH264Data(unsigned char *pData, int size);
	int WriteAacData(unsigned char *pData, int size);

private:
	int m_nWidth;
	int m_nHeight;
	int m_nFrameRate;
	int m_nVTimeScale;
	int m_nATimeScale;

	MP4TrackId m_audioId;
	MP4TrackId m_videoId;
	MP4FileHandle m_hMp4File;
};

Mp4Encoder::Mp4Encoder()
	: m_videoId(MP4_INVALID_TRACK_ID), m_audioId(MP4_INVALID_TRACK_ID), m_nWidth(0), m_nHeight(0), m_nVTimeScale(0), m_nFrameRate(0), m_hMp4File(NULL)
{
}

Mp4Encoder::~Mp4Encoder()
{
}

void Mp4Encoder::Start(const char *filename, int width, int height,
					   int vtimescale, int framerate, int atimescale)
{
	if (filename == NULL)
		return;

	m_hMp4File = MP4Create(filename);
	if (m_hMp4File == MP4_INVALID_FILE_HANDLE)
	{
		printf("ERROR:Open file fialed.\n");
		return;
	}

	m_nWidth = width;
	m_nHeight = height;
	m_nVTimeScale = 90000;
	m_nFrameRate = 25;
	m_nATimeScale = 48000;
}

void Mp4Encoder::Stop()
{
	if (m_hMp4File)
	{
		MP4Close(m_hMp4File);
		m_hMp4File = NULL;
	}
}

int Mp4Encoder::WriteH264Data(unsigned char *pData, int size)
{
	int type = pData[4] & 0x1f;

	if (type == 0x07)
	{ // sps

		// 添加h264 track
		if (m_videoId == MP4_INVALID_TRACK_ID)
		{
			m_videoId = MP4AddH264VideoTrack(m_hMp4File, m_nVTimeScale, m_nVTimeScale / m_nFrameRate, m_nWidth, // width
											 m_nHeight,															// height
											 pData[5],															// sps[1] AVCProfileIndication
											 pData[6],															// sps[2] profile_compat
											 pData[7],															// sps[3] AVCLevelIndication
											 3);																// 4 bytes length before each NAL unit
			if (m_videoId == MP4_INVALID_TRACK_ID)
			{
				printf("add video track failed.\n");
				return 0;
			}

			MP4SetVideoProfileLevel(m_hMp4File, 0x7F); //  Simple Profile @ Level
		}

		MP4AddH264SequenceParameterSet(m_hMp4File, m_videoId, pData + 4,
									   size - 4);
	}
	else if (type == 0x08)
	{ // pps
		MP4AddH264PictureParameterSet(m_hMp4File, m_videoId, pData + 4,
									  size - 4);
	}
	else
	{
		// MP4 Nalu前四个字节表示Nalu长度(no 00 00 00 01)
		pData[0] = (size - 4) >> 24;
		pData[1] = (size - 4) >> 16;
		pData[2] = (size - 4) >> 8;
		pData[3] = (size - 4) & 0xff;

		if (!MP4WriteSample(m_hMp4File, m_videoId, pData, size, MP4_INVALID_DURATION, 0, 1))
		{
			return 0;
		}
	}

	return 0;
}

int Mp4Encoder::WriteAacData(unsigned char *pData, int size)
{
	if (m_audioId == MP4_INVALID_TRACK_ID)
	{
		m_audioId = MP4AddAudioTrack(m_hMp4File, 48000, 1024, MP4_MPEG4_AUDIO_TYPE);
		if (m_audioId == MP4_INVALID_TRACK_ID)
		{
			printf("add audio track failed.\n");
			return 0;
		}

		MP4SetAudioProfileLevel(m_hMp4File, 0x2);
	}

	MP4WriteSample(m_hMp4File, m_audioId, pData, size, MP4_INVALID_DURATION, 0, 1);

	return 0;
}

int GetOneNalu(unsigned char *pBufIn, int nInSize, unsigned char *pNalu, int &nNaluSize)
{
	unsigned char *p = pBufIn;
	int nStartPos = 0, nEndPos = 0;

	while (1)
	{
		if (p[0] == 0 && p[1] == 0 && p[2] == 0 && p[3] == 1)
		{
			nStartPos = p - pBufIn;
			break;
		}

		p++;

		if (p - pBufIn >= nInSize - 4)
		{
			return 0;
		}
	}

	p++;

	while (1)
	{
		if (p[0] == 0 && p[1] == 0 && p[2] == 0 && p[3] == 1)
		{
			nEndPos = p - pBufIn;
			break;
		}

		p++;

		if (p - pBufIn >= nInSize - 4)
		{
			nEndPos = nInSize;
			break;
		}
	}

	nNaluSize = nEndPos - nStartPos;
	memcpy(pNalu, pBufIn + nStartPos, nNaluSize);

	return 1;
}

int GetOneAACFrame(unsigned char *pBufIn, int nInSize, unsigned char *pAACFrame,
				   int &nAACFrameSize)
{
	unsigned char *p = pBufIn;

	if (nInSize <= 7)
		return 0;

	int nFrameSize = ((p[3] & 0x3) << 11) + (p[4] << 3) + (p[5] >> 5);
	if (nInSize < nFrameSize)
		return 0;

	nAACFrameSize = nFrameSize;
	memcpy(pAACFrame, pBufIn, nFrameSize);

	return 1;
}

class CVideo
{
public:
	CVideo(string filename, Mp4Encoder *pencoder);
	~CVideo();

	int Write();

private:
	int m_TimeStamp;
	fstream m_File;
	int m_nFileSize;
	unsigned char *m_pBufferIn;
	unsigned char *m_pBufferOut;
	int m_nOffset;
	int m_count;
	Mp4Encoder *m_pencoder;
};

CVideo::CVideo(string filename, Mp4Encoder *pencoder)
	: m_TimeStamp(0), m_File(NULL), m_nFileSize(0), m_pBufferIn(NULL), m_pBufferOut(NULL), m_nOffset(0), m_count(0), m_pencoder(pencoder)
{
	m_File.open(filename.c_str(), ios::binary | ios::in);

	m_File.seekg(0, ios::end);
	m_nFileSize = m_File.tellg();

	m_File.seekg(0, ios_base::beg);

	m_pBufferIn = new unsigned char[m_nFileSize];
	m_pBufferOut = new unsigned char[m_nFileSize];

	m_File.read((char *)m_pBufferIn, m_nFileSize);
}

CVideo::~CVideo()
{
	delete m_pBufferIn;
	delete m_pBufferOut;

	m_File.close();
}

int CVideo::Write()
{
	int nNaluSize = 0;


	if (GetOneNalu(m_pBufferIn + m_nOffset, m_nFileSize - m_nOffset, m_pBufferOut,
				   nNaluSize) == 0)
	{
		// DEBUG("\n");
		return -1;
	}

	m_pencoder->WriteH264Data(m_pBufferOut, nNaluSize);

	if (m_pBufferOut[4] != 0x67 && m_pBufferOut[4] != 0x68)
	{
		m_TimeStamp += 33;
	}

	m_nOffset += nNaluSize;

	if (m_nOffset >= m_nFileSize - 4)
	{
		// DEBUG("\n");
		return -1;
	}

	m_count++;

	return m_TimeStamp;
};

class CAudio
{
public:
	CAudio(string filename, Mp4Encoder *pencoder);
	~CAudio();

	int Write();

private:
	int m_TimeStamp;
	std::fstream m_File;
	int m_nFileSize;
	unsigned char *m_pBufferIn;
	unsigned char *m_pBufferOut;
	int m_nOffset;
	int m_count;
	Mp4Encoder *m_pencoder;
};

CAudio::CAudio(string filename, Mp4Encoder *pencoder)
	: m_TimeStamp(0), m_File(NULL), m_nFileSize(0), m_pBufferIn(NULL), m_pBufferOut(NULL), m_nOffset(0), m_count(0), m_pencoder(pencoder)
{
	m_File.open(filename.c_str(), ios::binary | ios::in);

	m_File.seekg(0, ios::end);
	m_nFileSize = m_File.tellg();

	m_File.seekg(0, ios_base::beg);

	m_pBufferIn = new unsigned char[m_nFileSize];
	m_pBufferOut = new unsigned char[m_nFileSize];

	m_File.read((char *)m_pBufferIn, m_nFileSize);
}

CAudio::~CAudio()
{
	delete m_pBufferIn;
	delete m_pBufferOut;

	m_File.close();
}

int CAudio::Write()
{
	int nAACFrameSize = 0;

	if (GetOneAACFrame(m_pBufferIn + m_nOffset, m_nFileSize - m_nOffset, m_pBufferOut,
					   nAACFrameSize) == 0)
	{
		// DEBUG("\n");
		return -1;
	}

	printf("nAACFrameSize = %d\n", nAACFrameSize);
	m_pencoder->WriteAacData(m_pBufferOut, nAACFrameSize);

	m_TimeStamp += double(1024 * 1000) / double(44100);
	m_nOffset += nAACFrameSize;

	if (m_nOffset >= m_nFileSize - 4)
	{
		// DEBUG("\n");
		return -1;
	}

	m_count++;

	return m_TimeStamp;
}

int main()
{
	// // Create an empty mp4 file
	// MP4FileHandle mp4File = MP4Create("black_screen.mp4", 0);

	// // Set the timescale to the number of timeline ticks per second
	// MP4SetTimeScale(mp4File, 90000);

	// // Create the video track
	// MP4TrackId videoTrackId = MP4AddH264VideoTrack(
	//     mp4File,
	//     90000,
	//     MP4_INVALID_DURATION,
	//     1280,
	//     720,
	//     0,
	//     0,
	//     0,
	//     3);

	// // Create the audio track
	// MP4TrackId audioTrackId = MP4AddAudioTrack(
	//     mp4File,
	//     44100,
	//     1024,
	//     MP4_MPEG4_AUDIO_TYPE);

	// // Set the audio parameters
	// MP4SetAudioProfileLevel(mp4File, 0x0F);
	// MP4SetTrackESConfiguration(mp4File, audioTrackId, nullptr, 0);

	// // Add the black frames to the video track
	// for (int i = 0; i < 10; i++)
	// {
	//     MP4WriteSample(mp4File, videoTrackId, nullptr, 0, MP4_INVALID_DURATION, 0, 0);
	// }

	// // Add the silent audio frames
	// for (int i = 0; i < 10; i++)
	// {
	//     MP4WriteSample(mp4File, audioTrackId, nullptr, 0, MP4_INVALID_DURATION, 0, 0);
	// }

	// MP4Close(mp4File);
	uint32_t atime = 0, vtime = 0;
	bool bastop = false, bvstop = false;

	Mp4Encoder encoder;
	// encoder.Start
	// auto pVideo = new CVideo("124.mp4", &encoder);
	encoder.Start("test.mp4", 320, 240);

	unsigned char empty[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	encoder.WriteH264Data(empty, 9);

	// int timestamp = 0;

	// while (1) {
	// 	// if (bAudio && bVideo) {
	// 	// 	if (atime <= vtime && !bastop) {
	// 	// 		if ((timestamp = pAudio->Write()) < 0) {
	// 	// 			bastop = true;
	// 	// 		} else {
	// 	// 			atime = timestamp;
	// 	// 		}
	// 	// 	} else if (!bvstop) {
	// 	// 		if ((timestamp = pVideo->Write()) < 0) {
	// 	// 			bvstop = true;
	// 	// 		} else {
	// 	// 			vtime = timestamp;
	// 	// 		}
	// 	// 	}

	// 	// 	if (bastop && bvstop) {
	// 	// 		break;
	// 	// 	}
	// 	// } else if (bAudio) {
	// 	// 	if ((timestamp = pAudio->Write()) < 0) {
	// 	// 		break;
	// 	// 	}

	// 	// 	atime = timestamp;
	// 	// } else if (bVideo) {
	// 		if ((timestamp = pVideo->Write()) < 0) {
	// 			break;
	// 		}

	// 		vtime = timestamp;
	// 	//}
	// }

	// encoder.Stop();

	// if (pAudio != NULL)
	// 	delete pAudio;

	// if (pVideo != NULL)
	// 	delete pVideo;

	return 0;
}