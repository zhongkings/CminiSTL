#pragma once
#include "c_DataTypedef.h"

typedef struct {
	c_TYPE type;
	c_DATA **elements;
	c_INT size;
	c_INT capacity;
	c_OPEATIONFUN operate;
} c_Vector;

c_Vector* vecCreate();
c_Vector* vecCreateformLength(c_INT capacity);
c_Vector* vecCreateformVector(c_Vector *source);

c_VOID vecInsert(c_Vector *sourceTar, c_DATA *data, c_INT index);
c_VOID vecPushback(c_Vector *sourceTar, c_DATA *data);
c_DATA* vecErase(c_Vector *sourceTar, c_INT index);
c_DATA* vecEraseOfValue(c_Vector *sourceTar, c_DATA *data, c_INT begin);
c_DATA* vecPopback(c_Vector *sourceTar);

c_INT vecLength(c_Vector *sourceTar);
c_BOOL vecEmpty(c_Vector *sourceTar);
c_BOOL vecContains(c_Vector *sourceTar, c_DATA *data);
c_VOID vecShrink(c_Vector *sourceTar);
c_VOID vecCopy(c_Vector *directionTar, c_Vector *sourceTar);
c_VOID vecClear(c_Vector *sourceTar);
c_DATA* vecAt(c_Vector *sourceTar, c_INT index);
c_VOID vecExtend(c_Vector *sourceTar, c_EXTENDFUN efun);

c_VOID vecDestroy(c_Vector *sourceTar);