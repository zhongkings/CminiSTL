#pragma once
#include "Node/c_sinNode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	c_TYPE type;
	c_sinNode *head;
	c_sinNode *tail;
	c_INT size;
	c_OPEATIONFUN operate;
} c_SingleList;

c_SingleList* sinlistCreate();
c_SingleList* sinlistCreateformsinList(c_SingleList *sourceTar);

c_VOID sinlistInsert(c_SingleList *sourceTar, c_DATA *data, c_INT index);
c_VOID sinlistPushback(c_SingleList *sourceTar, c_DATA *data);
c_DATA* sinlistPopback(c_SingleList *sourceTar);
c_DATA* sinlistErase(c_SingleList *sourceTar, c_INT index);
c_DATA* sinlistEraseOfValue(c_SingleList *sourceTar, c_DATA *data, c_INT begin);

c_BOOL sinlistEnpty(c_SingleList *sourceTar);
c_INT  sinlistLength(c_SingleList *sourceTar);
c_BOOL sinlistContains(c_SingleList *sourceTar, c_DATA *data);
c_VOID sinlistCopy(c_SingleList *directionTar, c_SingleList *sourceTar);
c_VOID sinlistLink(c_SingleList *directionTar, c_SingleList *sourceTar, c_INT index);
c_VOID sinlistClear(c_SingleList *sourceTar);
c_DATA* sinlistAt(c_SingleList *sourceTar, c_INT index);
c_DATA* sinlistFront(c_SingleList *sourceTar);
c_DATA* sinlistBack(c_SingleList *sourceTar);
c_VOID  sinlistExtend(c_SingleList *sourceTar, c_EXTENDFUN efun);
//Node
c_sinNode* sinlistAtNode(c_SingleList *sourceTar, c_INT index);
c_sinNode* sinlistFrontNode(c_SingleList *sourceTar);
c_sinNode* sinlistBackNode(c_SingleList *sourceTar);

c_VOID sinlistDestroy(c_SingleList *sourceTar);