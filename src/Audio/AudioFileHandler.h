#ifndef AUDIOFILEHANDLER_H
#define AUDIOFILEHANDLER_H

#include <string>
#include <vector>
#include "../log.h"
#include <sndfile.h>



class AudioFileHandler {
public:
AudioFileHandler();
~AudioFileHandler();

	
		
	bool loadFile(	const std::string &filename,
					std::vector<float> &buffer,
					sf_count_t *frames,
					int *channels,
					int *sampleRate	);

	void unloadFile();



private:
	SNDFILE *sndfile;
	SF_INFO sfinfo;

};





#endif // AUDIOFILEHANDLER_H
