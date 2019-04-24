#pragma once
#include "c_SingleList.h"

typedef c_SingleList c_Queue;

c_Queue* queueCreate();
c_Queue* queueCreateformStack(c_Queue *sourceTar);
c_Queue* queueCreateformsinList(c_SingleList *sourceTar);

c_VOID queueBackPush(c_Queue *sourceTar, c_DATA *data);
c_DATA* queueFrontPop(c_Queue *sourceTar);

c_BOOL queueEmpty(c_Queue* sourceTar);
c_INT  queueLength(c_Queue* sourceTar);
c_VOID queueCopy(c_Queue *directionTar, c_Queue *sourceTar);
c_VOID queueClear(c_Queue *sourceTar);

//Node
c_sinNode* queueFrontPopNode(c_Queue *sourceTar);

c_VOID queueDestroy(c_Queue *sourceTar);