#ifndef PORT_AUDIO_MANAGER_H
#define PORT_AUDIO_MANAGER_H



#include "portaudio.h"
#include <iostream>
#include <cmath>

#define SAMPLE_RATE (44100.0)



class AudioManager {
public:
	AudioManager();
	~AudioManager();



	void play(double freq, double dur);



private:
	PaStream *stream;
	PaError err;


	
	static int paCallback(	const void *inputBuffer, void *outputBuffer,
							unsigned long framePerBuffer,
							const PaStreamCallbackTimeInfo *timeInfo,
							PaStreamCallbackFlags statusFlags,
							void *userData	);



	bool checkError(PaError err);
};





#endif //PORT_AUDIO_MANAGER_H
