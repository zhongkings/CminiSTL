#include "c_Queue.h"
#include <stdlib.h>
#include <stdio.h>

c_Queue* queueCreate() {
	return sinlistCreate();
}

c_Queue* queueCreateformStack(c_Queue *sourceTar) {
	return sinlistCreateformsinList(sourceTar);
}

c_Queue* queueCreateformsinList(c_SingleList *sourceTar) {
	return sinlistCreateformsinList(sourceTar);
}

c_VOID queueBackPush(c_Queue *sourceTar, c_DATA *data) {
	sinlistPushback(sourceTar, data);
}

c_DATA* queueFrontPop(c_Queue *sourceTar) {
	return sinlistFront(sourceTar);
}

c_BOOL queueEmpty(c_Queue* sourceTar) {
	return sourceTar->size == 0;
}
c_INT  queueLength(c_Queue* sourceTar) {
	return sourceTar->size;
}

c_VOID queueCopy(c_Queue *directionTar, c_Queue *sourceTar) {
	sinlistCopy(directionTar, sourceTar);
}

c_VOID queueClear(c_Queue *sourceTar) {
	sinlistClear(sourceTar);
}

//Node
c_sinNode* queueFrontPopNode(c_Queue *sourceTar) {
	return sinlistFrontNode(sourceTar);
}

c_VOID queueDestroy(c_Queue *sourceTar) {
	sinlistDestroy(sourceTar);
}