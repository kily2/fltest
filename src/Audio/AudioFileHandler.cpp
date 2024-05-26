

#include "AudioFileHandler.h"



AudioFileHandler::AudioFileHandler() 
: sndfile(nullptr),
frames(0),
currentFrame(0),
channels(0),
sampleRate(0) {
	
	//std::memset(&sfinfo, 0, sizeof(sfinfo));
}



AudioFileHandler::~AudioFileHandler() {
	unloadFile();
}



bool AudioFileHandler::loadFile(const std::string &filename) {
	
	unloadFile();


	sndfile = sf_open(filename.c_str(), SFM_READ, &sfinfo);
	if (!sndfile) {
		LOG("sndfile: Failed to open file.");
		return false;
	}
	

	buffer.resize(sfinfo.frames * sfinfo.channels);

	sf_count_t readFrames = sf_readf_float(sndfile, buffer.data(), sfinfo.frames);

	
	frames = readFrames;
	channels = sfinfo.channels;
	sampleRate = sfinfo.samplerate;
	currentFrame = 0;


	return true;
}



void AudioFileHandler::unloadFile() {
	if (sndfile) {
		sf_close(sndfile);
		sndfile=nullptr;
	}
	buffer.clear();
	frames=0;
	channels=0;
	sampleRate=0;
	currentFrame=0;
}



const std::vector<float>& AudioFileHandler::getBuffer() const {
	return buffer;
}



sf_count_t AudioFileHandler::getFrames() const {
	return frames;
}



int AudioFileHandler::getChannels() const {
	return channels;
}



int AudioFileHandler::getSampleRate() const {
	return sampleRate;
}



void AudioFileHandler::setCurrentFrame(sf_count_t new_frame) {
	currentFrame = new_frame;
}



sf_count_t AudioFileHandler::getCurrentFrame() const {
	return currentFrame;
}

