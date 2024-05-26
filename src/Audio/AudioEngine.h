#ifndef PORT_AUDIO_MANAGER_H
#define PORT_AUDIO_MANAGER_H



#include "portaudio.h"
#include <iostream>
#include <cmath>
#include "AudioFileHandler.h"


#define SAMPLE_RATE (44100.0)
#define TABLE_SIZE (44100)



class AudioManager {
public:
	AudioManager();
	~AudioManager();



	void play();



private:
	PaStream *stream;
	PaError err;

	AudioFileHandler audio_file_handler;	
	
		
	static int paCallback(	const void *inputBuffer, void *outputBuffer,
							unsigned long framePerBuffer,
							const PaStreamCallbackTimeInfo *timeInfo,
							PaStreamCallbackFlags statusFlags,
							void *userData	);



	bool checkError(PaError err);
};





#endif //PORT_AUDIO_MANAGER_H
