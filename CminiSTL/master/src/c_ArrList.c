#include "c_ArrList.h"
#include <stdlib.h>
#include <string.h>

c_ArrList* arrCreate() {
	c_ArrList * newVec = NULL;

	newVec = C_MALLOC(c_ArrList*, sizeof(c_ArrList), 1);

	newVec->size = 0;
	newVec->capacity = 10;
	newVec->type = c_VectorType;
	newVec->elements = C_MALLOC(c_DATA**, sizeof(c_DATA*), newVec->capacity);
	newVec->operate = NULL;

	return newVec;
}

c_ArrList* arrCreateformCapacity(c_INT capacity) {
	if (capacity < 0) return C_NULL;

	c_ArrList * newVec = C_MALLOC(c_ArrList*, sizeof(c_ArrList), 1);

	newVec->size = 0;
	newVec->capacity = capacity;
	newVec->type = c_VectorType;
	newVec->elements = C_MALLOC(c_DATA**, sizeof(c_DATA*), newVec->capacity);
	newVec->operate = NULL;

	return newVec;
}

c_ArrList* arrCreateformVector(c_ArrList *source) {
	c_ArrList * newVec = C_MALLOC(c_ArrList*, sizeof(c_ArrList), 1);

	newVec->size = source->size;
	newVec->capacity = source->capacity;
	newVec->operate = source->operate;	
	newVec->type = c_VectorType;
	newVec->elements = C_MALLOC(c_DATA**, sizeof(c_DATA*), newVec->capacity);
	for (c_INT i = 0; i < source->size; i++) {
		newVec->elements[i] = source->elements[i];
	}

	return newVec;
}

c_VOID arrInsert(c_ArrList *sourceTar, c_DATA *data, c_INT index) {
	if ((sourceTar->size + 1) >= sourceTar->capacity) {
		sourceTar->capacity *= 1.5;
		c_DATA **new_elements = C_MALLOC(c_DATA**, sizeof(c_DATA*), sourceTar->capacity);
		memcpy(new_elements, sourceTar->elements, sourceTar->size * sizeof(c_DATA*));

		C_FREE(sourceTar->elements);

		sourceTar->elements = new_elements;
	}

	for (c_INT i = sourceTar->size - 1; i >= index; i--)
		sourceTar->elements[i] = sourceTar->elements[i - 1];

	sourceTar->elements[index] = data;
	sourceTar->size++;
}

c_VOID arrPushback(c_ArrList *sourceTar, c_DATA *data) {
	//判断是否只剩下一个位置
	if ((sourceTar->size + 1) >= sourceTar->capacity) {
		sourceTar->capacity *= 1.5; //增加1.5倍
		c_DATA **new_elements = C_MALLOC(c_DATA**, sizeof(c_DATA*), sourceTar->capacity);
		memcpy(new_elements, sourceTar->elements, sourceTar->size * sizeof(c_DATA*));

		C_FREE(sourceTar->elements);

		sourceTar->elements = new_elements;
	}


	sourceTar->elements[sourceTar->size] = data;
	sourceTar->size++;
}

c_DATA* arrPopback(c_ArrList *sourceTar) {
	c_DATA *data = sourceTar->elements[sourceTar->size - 1];
	sourceTar->size--;

	return data;
}

c_DATA* arrErase(c_ArrList *sourceTar, c_INT index) {
	c_DATA *data = sourceTar->elements[index];
	for (c_INT i = index; i < sourceTar->size; i++) {
		sourceTar->elements[i] = sourceTar->elements[i + 1];
	}

	sourceTar->size--;

	return data;
}

c_DATA* arrEraseOfValue(c_ArrList *sourceTar, c_DATA *data, c_INT begin) {
	c_INT findindex = 0;
	for (c_INT i = begin; i < sourceTar->size; i++) {
		if (sourceTar->operate(sourceTar->elements[i], data, c_EQUAL)) {
			findindex = i;
			break;
		}
	}

	c_DATA *findata = sourceTar->elements[findindex];

	for (c_INT i = findindex; i < sourceTar->size; i++) {
		sourceTar->elements[i] = sourceTar->elements[i + 1];
	}
	sourceTar->size--;

	return findata;
}

c_INT arrLength(c_ArrList *sourceTar) {
	return sourceTar->size;
}

c_BOOL arrEmpty(c_ArrList *sourceTar) {
	return sourceTar->size == 0;
}

c_BOOL arrContains(c_ArrList *sourceTar, c_DATA *data) {
	if (sourceTar->size == 0 || data == C_NULL)
		return -1;

	for (c_INT i = 0; i < sourceTar->size; i++) {
		if (sourceTar->operate(sourceTar->elements[i], data, c_EQUAL))
			return c_TRUE;
	}

	return c_FALSE;
}

c_VOID arrShrink(c_ArrList *sourceTar) {
	sourceTar->capacity = (sourceTar->size + 5);

	c_DATA **new_elements = C_MALLOC(c_DATA**, sizeof(c_DATA*), sourceTar->capacity);
	memcpy(new_elements, sourceTar->elements, sourceTar->size * sizeof(c_DATA*));
	
	C_FREE(sourceTar->elements);

	sourceTar->elements = new_elements;
}

c_VOID arrCopy(c_ArrList *directionTar, c_ArrList *sourceTar) {
	C_FREE(directionTar->elements);

	directionTar->size = sourceTar->size;
	directionTar->capacity = directionTar->size + 5;
	directionTar->elements = C_MALLOC(c_DATA**, sizeof(c_DATA*), directionTar->capacity);
	for (c_INT i = 0; i < directionTar->size; i++) {
		directionTar->elements[i] = sourceTar->elements[i];
	}
}

c_VOID arrClear(c_ArrList *sourceTar) {
	C_FREE(sourceTar->elements);

	sourceTar->size = 0;
	sourceTar->capacity = 10;
	sourceTar->elements = C_MALLOC(c_DATA**, sizeof(c_DATA*), sourceTar->capacity);
}

c_DATA* arrAt(c_ArrList *sourceTar, c_INT index) {
	if (index < 0 || index >= sourceTar->size)
		index = sourceTar->size - 1;

	return sourceTar->elements[index];
}

c_VOID arrExtend(c_ArrList *sourceTar, c_EXTENDFUN efun) {
	for (c_INT i = 0; i < sourceTar->size; i++)
		efun(sourceTar->elements[i]);
}

c_VOID arrDestroy(c_ArrList *sourceTar) {
	C_FREE(sourceTar->elements);

	sourceTar->size = 0;
	sourceTar->capacity = 0;
	sourceTar->operate = C_NULL;
	sourceTar->elements = C_NULL;

	C_FREE(sourceTar);
}

