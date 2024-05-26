#ifndef AUDIOFILEHANDLER_H
#define AUDIOFILEHANDLER_H

#include <string>
#include <cstring>
#include <vector>
#include "../log.h"
#include <sndfile.h>



class AudioFileHandler {
public:
AudioFileHandler();
~AudioFileHandler();

	
		
	bool loadFile(const std::string &filename);
	void unloadFile();



	const std::vector<float>& getBuffer() const;
	sf_count_t getFrames() const;
	sf_count_t getCurrentFrame() const;
	int getChannels() const;
	int getSampleRate() const;



	void setCurrentFrame(sf_count_t frame);

private:
	SNDFILE *sndfile;
	SF_INFO sfinfo;



	std::vector<float> buffer;
	sf_count_t frames;
	sf_count_t currentFrame;
	int channels;
	int sampleRate;
		
};





#endif // AUDIOFILEHANDLER_H
