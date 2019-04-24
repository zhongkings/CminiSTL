#include "sample/util.h"
#include "c_Timer.h"
#include <stdio.h>

c_VOID SortAlgTimer(c_DATA *sourceTar, void(*sort)(c_DATA*, c_COMPAREVAR), c_COMPAREVAR comp, c_CHAR *sortName) {
	c_Timer *timer = timerCrate();

	timerStart(timer);
	sort(sourceTar, comp);
	timerStop(timer);
	printf("%s Timer: %.6f \n", sortName, timerGetElapsedTime(timer));

	timerDestroy(timer);
}