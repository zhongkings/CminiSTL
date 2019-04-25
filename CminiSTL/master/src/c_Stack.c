#include "c_Stack.h"
#include <stdlib.h>
#include <stdio.h>

c_Stack* stackCreate() {
	return sinlistCreate();
}

c_Stack* stackCreateformList(c_Stack *sourceTar) {
	return sinlistCreateformsinList(sourceTar);
}

c_Stack* stackCreateformStack(c_SingleList *sourceTar) {
	return sinlistCreateformsinList(sourceTar);
}

c_VOID stackPushback(c_Stack *sourceTar, c_DATA *data) {
	sinlistPushback(sourceTar, data);
}

c_DATA* stackPopback(c_Stack *sourceTar) {
	return sinlistPopback(sourceTar);
}

c_BOOL stackEmpty(c_Stack* sourceTar) {
	return sourceTar->size == 0;
}

c_INT stackLength(c_Stack* sourceTar) {
	return sourceTar->size;
}

c_VOID stackCopy(c_Stack *directionTar, c_Stack *sourceTar) {
	sinlistCopy(directionTar, sourceTar);
}

c_VOID stackClear(c_Stack *sourceTar) {
	sinlistClear(sourceTar);
}

//Node
c_sinNode* stackPopNode(c_Stack *sourceTar) {
	return sinlistBackNode(sourceTar);
}

c_VOID stackDestroy(c_Stack *sourceTar) {
	sinlistDestroy(sourceTar);
}