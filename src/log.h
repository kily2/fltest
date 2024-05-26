
#ifndef LOG_H
#define LOG_H


#include <cstdio>


#define LOGGING 1
#if LOGGING
#define LOG(msg) printf("LOG: %s",msg)
#define LOGF(msg,f) printf("LOG: %f, %s\n",f,msg)
#define LOGI(msg,i) printf("LOG: %d, %s\n",i,msg)
#define LOGS(msg,s) printf("LOG: %s, %s\n",s,msg)
#else
#define LOG(msg)
#define LOGF(msg,f)
#define LOGI(msg,i)
#define LOGS(msg,s)
#endif



#endif // LOG_H
