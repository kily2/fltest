

#include "portaudio.h"
#include "../include/port_audio_manager.h"
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



void AudioManager::play(double freq, double duration) {
	err = Pa_OpenDefaultStream(	&stream,
								0,
								1,
								paFloat32,
								SAMPLE_RATE,
								256,
								paCallback,
								&freq	);
	
	if (checkError(err)) return;



	err = Pa_StartStream(stream);
	if (checkError(err)) return;

	
	Pa_Sleep(static_cast<long>(duration));


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
    double frequency = *static_cast<double*>(userData);
    static double phase = 0.0;

    
	for (unsigned long i = 0; i < framesPerBuffer; i++) {
        *out++ = static_cast<float>(0.5 * sin(phase * 2.0 * M_PI));
        phase += frequency / SAMPLE_RATE;
        if (phase >= 1.0) phase -= 1.0;
    }

    
	return paContinue;	
}



bool AudioManager::checkError(PaError err) {
	if (err != paNoError) {
		std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
		return true;
	}

	return false;
}

