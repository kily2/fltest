

#include "portaudio.h"
#include "AudioEngine.h"
#include "../log.h"



AudioManager::AudioManager() {
	err = Pa_Initialize();
	if (checkError(err)) {
		LOG("PortAudio initialization failed.");
		return;
	}
}



AudioManager::~AudioManager() {
	if (stream) {
		Pa_StopStream(stream);
		Pa_CloseStream(stream);
	}

	err = Pa_Terminate();
	if (checkError(err)) {
		LOG("PA termination failed");
	}
}



void AudioManager::play(paTestData* data) {
	

	err = Pa_OpenDefaultStream(	&stream,
								0,
								2,
								paFloat32,
								SAMPLE_RATE,
								256,
								paCallback,
								data	);
	
	if (checkError(err)) return;



	err = Pa_StartStream(stream);
	if (checkError(err)) return;


	Pa_Sleep(2000);


	err = Pa_StopStream(stream);
	if (checkError(err)) return;


	err = Pa_CloseStream(stream);
	if (checkError(err)) return;


	stream = nullptr;
}



int AudioManager::paCallback(	const void *inputBuffer, void *outputBuffer,
								unsigned long framesPerBuffer,
								const PaStreamCallbackTimeInfo *timeInfo,
								PaStreamCallbackFlags statusFlags,
								void *userData	) {
    

	float* out = static_cast<float*>(outputBuffer);
    paTestData *data = static_cast<paTestData*>(userData);
	unsigned int i;
	(void) inputBuffer;
    
	for (i = 0; i < framesPerBuffer; i++) {
        *out++ = data->sine[data->phase];
		*out++ = data->sine[data->phase];
		data->phase +=1;
		if (data->phase >= data->current_size) data->phase-=data->current_size; 
    }

    
	return 0;	
}



bool AudioManager::checkError(PaError err) {
	if (err != paNoError) {
		std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
		return true;
	}

	return false;
}

