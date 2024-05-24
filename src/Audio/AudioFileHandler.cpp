

#include "AudioFileHandler.h"



AudioFileHandler::AudioFileHandler() 
: sndfile(nullptr) {
	//...
}



AudioFileHandler::~AudioFileHandler() {
	unloadFile();
}



bool AudioFileHandler::loadFile(const std::string &filename,
								std::vector<float> &buffer,
								sf_count_t *frames,
								int *channels,
								int *sampleRate) {
	
	unloadFile();


	sndfile = sf_open(filename.c_str(), SFM_READ, &sfinfo);
	if (sndfile) {
		return false;
	}
	

	buffer.resize(sfinfo.frames * sfinfo.channels);

	sf_count_t readFrames = sf_readf_float(sndfile, buffer.data(), sfinfo.frames);


	if (frames) {
		*frames = readFrames;
	}


	if (channels) {
		*channels = sfinfo.channels;
	}


	if (sampleRate) {
		*sampleRate = sfinfo.samplerate;
	}

	return true;
}



void AudioFileHandler::unloadFile() {
	if (sndfile) {
		sf_close(sndfile);
		sndfile=nullptr;
	}
}









