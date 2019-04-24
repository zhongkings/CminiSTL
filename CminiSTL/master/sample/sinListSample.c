#include "c_SingleList.h"
#include "c_String.h"

void sinListStrInit(c_SingleList *obj) {
	c_String *strs[10] = {
		strAssignChars("Zhong"), strAssignChars("Quan"), strAssignChars("Pei"),
		strAssignChars("My"), strAssignChars("ZhanShi"), strAssignChars("Dog"),
		strAssignChars("Pig"),  strAssignChars("Cat"),  strAssignChars("阿尔特留斯"),
		strAssignChars("暗月之剑")
	};

	for (int i = 0; i < 10; i++)
		sinlistPushback(obj, strs[i]);
}

c_VOID cSTRprintf(c_String *str) {
	printf("%s \n", str->chars);
}

void sinListmain() {
	c_SingleList *sinList = sinlistCreate();
	sinList->operate = strOperate;
	sinListStrInit(sinList);

	c_SingleList *sinList2 = sinlistCreate(); sinList2->operate = strOperateChar;
	c_String *Wolfcn = strAssignChars("只狼"); sinlistInsert(sinList2, Wolfcn, 0);
	c_String *Wolfen = strAssignChars("Wolf"); sinlistInsert(sinList2, Wolfen, sinList2->size);
	sinlistLink(sinList2, sinList, 0);
	sinlistEraseOfValue(sinList2, "暗月之剑", 0);
	printf("sinList2 size:%d\n", sinList2->size);
	while (sinList2->size != 0) {
		cSTRprintf(sinlistPopback(sinList2));
	}
	printf("sinList2 size:%d\n", sinList2->size);
}