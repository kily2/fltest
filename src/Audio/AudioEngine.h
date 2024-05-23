#ifndef PORT_AUDIO_MANAGER_H
#define PORT_AUDIO_MANAGER_H



#include "portaudio.h"
#include <iostream>
#include <cmath>

#define SAMPLE_RATE (44100.0)
#define TABLE_SIZE (44100)



typedef struct {

	float sine[TABLE_SIZE];
	int phase;
	int current_size;

} paTestData;



class AudioManager {
public:
	AudioManager();
	~AudioManager();



	void play(paTestData* data);



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
