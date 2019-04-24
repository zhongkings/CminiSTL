#include "sample/sample.h"
#include "c_String.h"

void Stringmain() {
	c_String *str1 = strAssignChars("TheShy");
	c_String *str2 = strAssignCharsoffset("Semb", 0, 3);
	c_String *str3 = strAssignStr(str1);
	c_String *str4 = strAssignStroffset(str1, 3, 5);
	c_String *strlink = strLinks(str1, str2);
	c_String *Quan = strAssignChars("My Name ZhongPeiQuan");
	c_String *subQuan = strSubstring(Quan, 8, 19);
	printf("str:%s len:%d \n", str1->chars, str1->length);
	printf("str:%s len:%d \n", str2->chars, str2->length);
	printf("str:%s len:%d \n", str3->chars, str3->length);
	printf("str:%s len:%d \n", str4->chars, str4->length);
	printf("str:%s len:%d \n", strlink->chars, strlink->length);
	printf("str:%s len:%d \n", strChars(Quan), strLength(Quan));
	printf("str:%s len:%d \n", strChars(subQuan), strLength(subQuan));
	printf("Equal{str1, str3} = %d \n", strOperate(str1, str3, c_EQUAL));
	printf("Equal{str1, str3} = %d \n", strOperate(str1, str2, c_Greater));
	printf("Equal{str1, str3} = %d \n", strOperateChar(str1, "TheShy", c_EQUAL));
}