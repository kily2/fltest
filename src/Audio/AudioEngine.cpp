

#include "portaudio.h"
#include "AudioEngine.h"
#include "../log.h"



AudioManager::AudioManager() {
	err = Pa_Initialize();
	if (checkError(err)) {
		LOG("PortAudio initialization failed.");
		return;
	}



	std::string filename = "tests/test_kick1.wav";

	if (!audio_file_handler.loadFile(filename)) {
		return;
	}


	std::cout << "channels: " << audio_file_handler.getChannels() << std::endl;	
	std::cout << "samplerate: " << audio_file_handler.getSampleRate() << std::endl;


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



void AudioManager::play() {
	

	err = Pa_OpenDefaultStream(	&stream,
								0,
								audio_file_handler.getChannels(),
								paFloat32,
								audio_file_handler.getSampleRate(),
								paFramesPerBufferUnspecified,
								paCallback,
								&audio_file_handler	);
	
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
    
	AudioFileHandler *handler = static_cast<AudioFileHandler*>(userData);
	float *out = static_cast<float*>(outputBuffer);
	unsigned long i;



	sf_count_t framesLeft = handler->getFrames() - handler->getCurrentFrame();
	unsigned long framesToCopy = (framesLeft<framesPerBuffer)?framesLeft:framesPerBuffer;



	const float *input = handler->getBuffer().data() + handler->getCurrentFrame()*handler->getChannels();
	for (i=0; i<framesToCopy*handler->getChannels(); i++) {
		*out++ = *input++;
	}
	


	handler->setCurrentFrame(handler->getCurrentFrame() + framesToCopy);



	if (framesToCopy < framesPerBuffer) {
		for(; i< framesPerBuffer*handler->getChannels(); i++) {
			*out++ = 0.0f;
		}
		return paComplete;
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

