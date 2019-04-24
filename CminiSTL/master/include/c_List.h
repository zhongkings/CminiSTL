#pragma once
#include "Node/c_douNode.h"

typedef struct {
	c_TYPE type;
	c_douNode *head;
	c_douNode *tail;
	c_INT size;
	c_OPEATIONFUN operate;
} c_List;

c_List* listCreate();
c_List* listCreateformList(c_List *sourceTar);

c_VOID listInsert(c_List *sourceTar, c_DATA *data, c_INT index);
c_VOID listPushback(c_List *sourceTar, c_DATA *data);
c_DATA* listPopback(c_List *sourceTar);
c_VOID listErase(c_List *sourceTar, c_INT index);
c_VOID listEraseOfValue(c_List *sourceTar, c_DATA *data, c_INT begin);


c_BOOL  listEmpty(c_List *sourceTar);
c_INT   listLength(c_List *sourceTar);
c_BOOL  listContains(c_List *sourceTar, c_DATA *data);
c_VOID  listCopy(c_List *directionTar, c_List *sourceTar);
c_VOID  listLink(c_List *directionTar, c_List *sourceTar, c_INT index);
c_VOID  listClear(c_List *sourceTar);
c_DATA* listAt(c_List *sourceTar, c_INT index);
c_DATA* listFront(c_List *sourceTar);
c_DATA* listBack(c_List *sourceTar);
c_VOID  listExtend(c_List *sourceTar, c_EXTENDFUN efun);
//Node
c_douNode* listAtNode(c_List *sourceTar, c_INT index);
c_douNode* listFrontNode(c_List *sourceTar);
c_douNode* listBackNode(c_List *sourceTar);

c_VOID listDestroy(c_List *sourceTar);