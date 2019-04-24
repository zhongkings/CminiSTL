#pragma once
#include "c_DataTypedef.h"

typedef struct {
	c_CHAR *chars;
	c_INT length;
} c_String;

c_String* strAssignStr(c_String *sourceTar);
c_String* strAssignChars(c_CHAR *source);
c_String* strAssignCharsoffset(c_CHAR *source, c_INT begin, c_INT end);
c_String* strAssignStroffset(c_String *sourceTar, c_INT begin, c_INT end);

//连接字符串
c_String* strLinks(c_String *sourceTar1, c_String *sourceTar2);
//包含指定字符 返回该字符串第一次出现的索引
c_INT strValueOf(c_String *sourceTar, c_String *subTar,c_INT begin);
c_INT strValueOfChar(c_String *sourceTar, c_CHAR *subTar,c_INT begin);
//包含指定字符 返回该字符串按给出最后一次出现的索引 使用KMP算法查找
c_INT strValueOfEnd(c_String *sourceTar, c_String *subTar, c_INT begin);
c_INT strValueOfCharEnd(c_String *sourceTar, c_CHAR *subTar, c_INT begin);
//对比字符串
c_BOOL strEqual(c_String *str1, c_String *str2);
c_BOOL strEqualChar(c_String *str1, c_CHAR *str2);
c_BOOL strOperate(c_String *str1, c_String *str2, c_COMPAREVAR compvar);
c_BOOL strOperateChar(c_String *str1, c_CHAR *str2, c_COMPAREVAR compvar);
//判断是否空字符串
c_INT strEmpty(c_String *sourceTar);
//返回长度
c_INT strLength(c_String *sourceTar);
//返回chars
c_CHAR* strChars(c_String *sourceTar);
//返回子字符串 begin end
c_String* strSubstring(c_String *sourceTar, c_INT begin, c_INT end);
//index字符
c_CHAR strCharAt(c_String *sourceTar, c_INT index);
//销毁字符串
c_VOID strDestory(c_String *sourceTar);