
#ifndef LOG_H
#define LOG_H


#include <cstdio>


#define LOGGING 1
#if LOGGING
#define LOG(msg) printf("LOG: %s",msg)
#define LOGF(msg,f) printf("LOG: %f, %s\n",f,msg)
#else
#define LOG(msg)
#define LOGF(msg,f)
#endif



#endif // LOG_H
