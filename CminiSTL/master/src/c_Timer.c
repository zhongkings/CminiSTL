#include"c_Timer.h"
#include<stdlib.h>
c_Timer* timerCrate() {

	c_Timer *newTimer = C_MALLOC(c_Timer*, sizeof(c_Timer), 1);

#if defined(WIN32) || defined(_WIN32)
	QueryPerformanceFrequency(&newTimer->frequency);
	newTimer->startCount.QuadPart = 0;
	newTimer->endCount.QuadPart = 0;
#else
	newTimer->startCount.tv_sec = newTimer->startCount.tv_usec = 0;
	newTimer->endCount.tv_sec = newTimer->endCount.tv_sec = 0;
#endif

	newTimer->stopped = 0;
	newTimer->startTimeInMicroSec = 0;
	newTimer->endTimeInMicroSec = 0;

	return newTimer;
}

c_VOID timerDestroy(c_Timer *timer) {
	C_FREE(timer);
}

c_VOID timerStart(c_Timer *timer) {
	timer->stopped = 0;

#if defined(WIN32) || defined(_WIN32)
	QueryPerformanceCounter(&timer->startCount);
#else
	gettimeofday(&timer->startCount, NULL);
#endif

	return;
}

c_VOID timerStop(c_Timer *timer) {
	timer->stopped = 1;

#if defined(WIN32) || defined(_WIN32)
	QueryPerformanceCounter(&timer->endCount);
#else
	gettimeofday(&timer->endCount, NULL);
#endif

	return;
}

c_DOUBLE timerGetElapsedTimeInMicroSec(c_Timer *timer) {
#if defined(WIN32) || defined(_WIN32)
	if (!timer->stopped)
		QueryPerformanceCounter(&timer->endCount);

	timer->startTimeInMicroSec = timer->startCount.QuadPart * (1000000.0 / timer->frequency.QuadPart);
	timer->endTimeInMicroSec = timer->endCount.QuadPart * (1000000.0 / timer->frequency.QuadPart);
#else
	if (!timer->stopped)
		gettimeofday(&timer->endCount.NULL);

	timer->startTimeInMicroSec = (timer->startCount.tv_sec * 1000000.0) + timer->startCount.tv_usec;
	timer->endTimeInMicroSec = (timer->endCount.tv_sec * 1000000.0) + timer->endCount.tv_usec;
#endif

	return timer->endTimeInMicroSec - timer->startTimeInMicroSec;
}

c_DOUBLE timerGetElapsedTime(c_Timer *timer) {
	return timerGetElapsedTimeInMicroSec(timer) * 0.000001;
}

c_DOUBLE timerGetElapsedTimeInMilliSec (c_Timer *timer) {
	return timerGetElapsedTimeInMicroSec(timer) * 0.001;
}

c_DOUBLE timerGetElapsedTimeInSec(c_Timer *timer) {
	return timerGetElapsedTimeInMicroSec(timer) * 0.000001;

}
