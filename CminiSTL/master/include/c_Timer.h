#pragma once
#include "c_DataTypedef.h"

#if defined(WIN32) || defined(_WIN32)//Windows
#include <Windows.h>
#else //Unix
#include <sys/time.h>
#endif

typedef struct {
	c_DOUBLE startTimeInMicroSec; //start Time Sec
	c_DOUBLE endTimeInMicroSec;   //end Time Sec
	c_BOOL stopped;                //stop flag

#if defined(WIN32) || defined(_WIN32)
	LARGE_INTEGER frequency;
	LARGE_INTEGER startCount;
	LARGE_INTEGER endCount;
#else
	timeval startCount;
	timeval endCount;
#endif
} c_Timer;

c_Timer* timerCrate();
c_VOID timerDestroy(c_Timer*);
c_VOID timerStart(c_Timer*);
c_VOID timerStop(c_Timer*);
c_DOUBLE timerGetElapsedTime(c_Timer*);
c_DOUBLE timerGetElapsedTimeInSec(c_Timer*);      //√Î
c_DOUBLE timerGetElapsedTimeInMilliSec(c_Timer*); //∫¡
c_DOUBLE timerGetElapsedTimeInMicroSec(c_Timer*); //Œ¢
