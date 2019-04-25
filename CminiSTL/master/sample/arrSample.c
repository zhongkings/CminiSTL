#include "c_ArrList.h"
#include "sample/sample.h"

c_VOID ForInsert(c_ArrList *sourceTar, c_INT begin, c_INT end) {
	for (begin; begin <= end; begin++) {
		c_INT *varptr = C_MALLOC(c_INT*, sizeof(c_INT), 1);
		*varptr = begin;
		arrPushback(sourceTar, varptr);
	}
}

c_VOID ForInsertRand(c_ArrList *sourceTar, c_INT begin, c_INT end) {
	for (begin; begin <= end; begin++) {
		c_INT *varptr = C_MALLOC(c_INT*, sizeof(c_INT), 1);
		*varptr = rand(begin) % end;
		arrPushback(sourceTar, varptr);
	}
}

c_VOID Exfun(c_DATA *data){
	printf("%d ", *(c_INT*)data);

}

c_VOID arrProp(c_ArrList *sourecTar) {
	printf("\nsize: %d,capacity: %d \n", sourecTar->size, sourecTar->capacity);
}

c_BOOL arrIntOperate(c_DATA *first, c_DATA *second, c_COMPAREVAR compvar) {
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

void Arrmain() {
	srand(time(0));
	c_Timer *timer = timerCrate();
	c_ArrList *bubble_intArr = arrCreate();
	bubble_intArr->operate = arrIntOperate;

	ForInsertRand(bubble_intArr, 0, 2500);
	c_ArrList *select_intArr = arrCreateformVector(bubble_intArr);
	c_ArrList *insert_intArr = arrCreateformVector(bubble_intArr);
	c_ArrList *shells_intArr = arrCreateformVector(bubble_intArr);
	arrExtend(insert_intArr, Exfun); printf("\n");

	SortAlgTimer(bubble_intArr, BubbleSort, c_LESS, "vecBubbleSort(2500)"); arrExtend(bubble_intArr, Exfun); printf("\n");
	SortAlgTimer(select_intArr, SelectSort, c_LESS, "vecSelectSort(2500)"); arrExtend(select_intArr, Exfun); printf("\n");
	SortAlgTimer(insert_intArr, InsertSort, c_LESS, "vecInsertSort(2500)"); arrExtend(insert_intArr, Exfun); printf("\n");
	SortAlgTimer(shells_intArr, ShellSort , c_LESS, "vecShellsSort(2500)"); arrExtend(shells_intArr, Exfun); printf("\n");
}