#include "c_List.h"
#include "c_Algorithm.h"
#include "c_Timer.h"
#include "sample/sample.h"

c_VOID listIntPushback(c_List *sourceTar, c_INT i) {
	c_INT *ptr = C_MALLOC(c_INT*, sizeof(c_INT), 1);
	*ptr = i;

	listPushback(sourceTar, ptr);
}

c_VOID listIntInsert(c_List *sourceTar, c_INT i, c_INT index) {
	c_INT *ptr = C_MALLOC(c_INT*, sizeof(c_INT), 1);
	*ptr = i;

	listInsert(sourceTar, ptr, index);
}

c_VOID listBeginandEnd(c_List *sourceTar, c_INT begin, c_INT end) {
	for (begin; begin <= end; begin++) {
		c_INT *varptr = C_MALLOC(c_INT*, sizeof(c_INT), 1);
		*varptr = rand() % end;
		listPushback(sourceTar, varptr);
	}
}

c_VOID listPrintEx(c_DATA *data) {
	if (data == C_NULL)
		return;

	printf("%d ", *(c_INT*)data);
}

c_BOOL listIntOperate(c_DATA *first, c_DATA *second, c_COMPAREVAR compvar) {
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
		if (*(c_INT*)first == *(c_INT*)second) {
			cbool = c_TRUE;
		}
		break;
	}

	return cbool;
}


void Listmain() {
	srand((c_UINT)time(0));
	c_List *Bubble_listint = listCreate(sizeof(c_INT));
	Bubble_listint->operate = listIntOperate;
	listBeginandEnd(Bubble_listint, 1, 2500);
	c_List *Select_listint = listCreateformList(Bubble_listint);
	c_List *Insert_listint = listCreateformList(Bubble_listint);
	c_List *Shells_listInt = listCreateformList(Bubble_listint);

	SortAlgTimer(Bubble_listint, BubbleSort, c_LESS, "listBubbleSort(2500)"); //listExtend(Bubble_listint, listPrintEx); printf("\n");
	SortAlgTimer(Select_listint, SelectSort, c_LESS, "listSelectSort(2500)"); //listExtend(Select_listint, listPrintEx); printf("\n");
	SortAlgTimer(Insert_listint, InsertSort, c_LESS, "listInsertSort(2500)"); //listExtend(Insert_listint, listPrintEx); printf("\n");
	SortAlgTimer(Shells_listInt, InsertSort, c_LESS, "listShellsSort(2500)"); //listExtend(Shells_listInt, listPrintEx); printf("\n");
}