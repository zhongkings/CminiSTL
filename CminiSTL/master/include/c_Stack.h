#pragma once
#include "c_SingleList.h"

typedef c_SingleList c_Stack;

c_Stack* stackCreate();
c_Stack* stackCreateformStack(c_Stack *sourceTar);
c_Stack* stackCreateformsinList(c_SingleList *sourceTar);

c_VOID stackPushback(c_Stack *sourceTar, c_DATA *data);
c_DATA* stackTop(c_Stack *sourceTar);

c_BOOL  stackEmpty(c_Stack* sourceTar);
c_INT   stackLength(c_Stack* sourceTar);
c_VOID  stackCopy(c_Stack *directionTar, c_Stack *sourceTar);
c_VOID  stackClear(c_Stack *sourceTar);

//Node
c_sinNode* stackTopNode(c_Stack *sourceTar);

c_VOID stackDestroy(c_Stack *sourceTar);
