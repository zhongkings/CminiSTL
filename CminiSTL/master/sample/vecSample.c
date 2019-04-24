#include "c_Vector.h"
#include "sample/sample.h"

c_VOID ForInsert(c_Vector *sourceTar, c_INT begin, c_INT end) {
	for (begin; begin <= end; begin++) {
		c_INT *varptr = C_MALLOC(c_INT*, sizeof(c_INT), 1);
		*varptr = begin;
		vecPushback(sourceTar, varptr);
	}
}

c_VOID ForInsertRand(c_Vector *sourceTar, c_INT begin, c_INT end) {
	for (begin; begin <= end; begin++) {
		c_INT *varptr = C_MALLOC(c_INT*, sizeof(c_INT), 1);
		*varptr = rand(begin) % end;
		vecPushback(sourceTar, varptr);
	}
}

c_VOID Exfun(c_DATA *data){
	printf("%d ", *(c_INT*)data);

}

c_VOID vecProp(c_Vector *sourecTar) {
	printf("\nsize: %d,capacity: %d \n", sourecTar->size, sourecTar->capacity);
}

c_BOOL vecIntOperate(c_DATA *first, c_DATA *second, c_COMPAREVAR compvar) {
	c_BOOL cbool = c_FALSE;

	switch (compvar) {
	case c_LESS:
		if (*(c_INT*)first < *(c_INT*)second)
			cbool = c_TRUE;
		break;
	case c_Greater:
		if (*(c_INT*)first > *(c_INT*)second)
			cbool = c_TRUE;
		break;
	case c_EQUAL:
		if (*(c_INT*)first == *(c_INT*)second)
			cbool = c_TRUE;
		break;
	}

	return cbool;
}

void Vecmain() {
	srand(time(0));
	c_Timer *timer = timerCrate();
	c_Vector *bubble_intVec = vecCreate();
	bubble_intVec->operate = vecIntOperate;

	ForInsertRand(bubble_intVec, 0, 2500);
	c_Vector *select_intVec = vecCreateformVector(bubble_intVec);
	c_Vector *insert_intVec = vecCreateformVector(bubble_intVec);
	c_Vector *shells_intVec = vecCreateformVector(bubble_intVec);
	vecExtend(insert_intVec, Exfun); printf("\n");

	SortAlgTimer(bubble_intVec, BubbleSort, c_LESS, "vecBubbleSort(2500)"); vecExtend(bubble_intVec, Exfun); printf("\n");
	SortAlgTimer(select_intVec, SelectSort, c_LESS, "vecSelectSort(2500)"); vecExtend(select_intVec, Exfun); printf("\n");
	SortAlgTimer(insert_intVec, InsertSort, c_LESS, "vecInsertSort(2500)"); vecExtend(insert_intVec, Exfun); printf("\n");
	SortAlgTimer(shells_intVec, ShellSort , c_LESS, "vecShellsSort(2500)"); vecExtend(shells_intVec, Exfun); printf("\n");
}