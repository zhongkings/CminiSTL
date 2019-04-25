#pragma once
#include "c_DataTypedef.h"

typedef struct {
	c_TYPE type;
	c_DATA **elements;
	c_INT size;
	c_INT capacity;
	c_OPEATIONFUN operate;
} c_ArrList;

c_ArrList* arrCreate();
c_ArrList* arrCreateformLength(c_INT capacity);
c_ArrList* arrCreateformVector(c_ArrList *source);

c_VOID arrInsert(c_ArrList *sourceTar, c_DATA *data, c_INT index);
c_VOID arrPushback(c_ArrList *sourceTar, c_DATA *data);
c_DATA* arrErase(c_ArrList *sourceTar, c_INT index);
c_DATA* arrEraseOfValue(c_ArrList *sourceTar, c_DATA *data, c_INT begin);
c_DATA* arrPopback(c_ArrList *sourceTar);

c_INT arrLength(c_ArrList *sourceTar);
c_BOOL arrEmpty(c_ArrList *sourceTar);
c_BOOL arrContains(c_ArrList *sourceTar, c_DATA *data);
c_VOID arrShrink(c_ArrList *sourceTar);
c_VOID arrCopy(c_ArrList *directionTar, c_ArrList *sourceTar);
c_VOID arrClear(c_ArrList *sourceTar);
c_DATA* arrAt(c_ArrList *sourceTar, c_INT index);
c_VOID arrExtend(c_ArrList *sourceTar, c_EXTENDFUN efun);

c_VOID arrDestroy(c_ArrList *sourceTar);