#include "c_String.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define ENDCHARBIT 1

c_String* strAssignStr(c_String *sourceTar) {
	c_String *newStr = C_MALLOC(c_String*, sizeof(c_String), 1);
	newStr->length = sourceTar->length;
	newStr->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), newStr->length);
	if (newStr->chars == C_NULL) return C_NULL;
	strcpy(newStr->chars, sourceTar->chars);

	return newStr;
}

c_String* strAssignChars(c_CHAR *source) {
	c_String *newStr = C_MALLOC(c_String*, sizeof(c_String), 1);
	newStr->length = strlen(source);
	newStr->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), newStr->length + ENDCHARBIT);
	if (newStr->chars == C_NULL) return C_NULL;
	strcpy(newStr->chars, source);

	return newStr;
}

//abc 3 + 1 = 4 
c_String* strAssignCharsoffset(c_CHAR *source, c_INT begin, c_INT end) {
	c_INT len = strlen(source);
	if (end >= len || begin >= end) return C_NULL;

	c_String *newStr = C_MALLOC(c_String*, sizeof(c_String), 1);
	newStr->length = (end - begin) + 1;
	newStr->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), newStr->length + ENDCHARBIT); //这一步加多一个是结尾符的
	if (newStr->chars == C_NULL) return C_NULL;
	for (int i = begin, j = 0; i <= end; i++, j++)
		newStr->chars[j] = source[i];

	newStr->chars[newStr->length] = '\0';
	return newStr;
}

c_String* strAssignStroffset(c_String *sourceTar, c_INT begin, c_INT end) {
	if (end >= sourceTar->length || begin >= end) return C_NULL;

	c_String *newStr = C_MALLOC(c_String*, sizeof(c_String), 1);
	newStr->length = (end - begin) + 1;
	newStr->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), newStr->length + ENDCHARBIT); //这一步加多一个是结尾符的
	if (newStr->chars == C_NULL) return C_NULL;
	for (int i = begin, j = 0; i <= end; i++, j++)
		newStr->chars[j] = sourceTar->chars[i];
	newStr->chars[newStr->length] = '\0';
	return newStr;
}

//连接字符串
c_String* strLinks(c_String *sourceTar1, c_String *sourceTar2) {
	c_String *newStr = C_MALLOC(c_String*, sizeof(c_String), 1);
	newStr->length = sourceTar1->length + sourceTar2->length;
	newStr->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), newStr->length + ENDCHARBIT); //这一步加多一个是结尾符的
	if (newStr->chars == C_NULL) return C_NULL;
	int j = 0;
	for (int i = 0; i < sourceTar1->length; i++, j++)
		newStr->chars[j] = sourceTar1->chars[i];
	for (int i = 0; i < sourceTar2->length; i++, j++)
		newStr->chars[j] = sourceTar2->chars[i];
	newStr->chars[newStr->length] = '\0';

	return newStr;
}

//对比字符串
c_BOOL strEqual(c_String *str1, c_String *str2) {
	int str1len = str1->length;
	int str2len = str2->length;
	if (str1len != str2len)
		return c_FALSE;

	for (int i = 0; i < str1len; i++)
		if (str1->chars[i] != str2->chars[i])
			return c_FALSE;

	return c_TRUE;
}

c_BOOL strEqualChar(c_String *str1, c_CHAR *str2) {
	int str1len = str1->length;
	int str2len = strlen(str2);
	if (str1len != str2len)
		return c_FALSE;

	for (int i = 0; i < str1len; i++)
		if (str1->chars[i] != str2[i])
			return c_FALSE;

	return c_TRUE;
}

c_BOOL strOperate(c_String *str1, c_String *str2, c_COMPAREVAR compvar) {
	int forlen = (str1->length > str2->length) ? str1->length : str2->length;

	switch (compvar) {
	case c_LESS:
		for (int i = 0; i < forlen; i++)
			if (strCharAt(str1, i) == strCharAt(str2, i))
				continue;
			else if (strCharAt(str1, i) < strCharAt(str2, i))
				return c_TRUE;
			else 
				return c_FALSE;
		break;

	case c_EQUAL:
		if (str1->length != str2->length)
			return c_FALSE;
		for (int i = 0; i < str1->length; i++)
			if (str1->chars[i] != str2->chars[i])
				return c_FALSE;
		return c_TRUE;
		break;

	case c_Greater:
		for (int i = 0; i < forlen; i++)
			if (strCharAt(str1, i) == strCharAt(str2, i))
				continue;
			else if (strCharAt(str1, i) > strCharAt(str2, i))
				return c_TRUE;
			else
				return c_FALSE;
		break;
	}

	return c_FALSE;
}

c_BOOL strOperateChar(c_String *str1, c_CHAR *str2, c_COMPAREVAR compvar) {
	int str2len = strlen(str2);
	int forlen = (str1->length > str2len) ? str1->length : str2len;

	switch (compvar) {
	case c_LESS:
		for (int i = 0, j = 0; i < forlen; i++, j++) {
			if (j >= str2len)
				j = str2len - 1;

			if (strCharAt(str1, i) == str2[j])
				continue;
			else if (strCharAt(str1, i) < str2[j])
				return c_TRUE;
			else
				return c_FALSE;
		}
		break;

	case c_EQUAL:
		if (str1->length != str2len)
			return c_FALSE;
		for (int i = 0; i < str1->length; i++)
			if (str1->chars[i] != str2[i])
				return c_FALSE;
		return c_TRUE;
		break;

	case c_Greater:
		for (int i = 0, j = 0; i < forlen; i++, j++) {
			if (j >= str2len)
				j = str2len - 1;

			if (strCharAt(str1, i) == str2[j])
				continue;
			else if (strCharAt(str1, i) > str2[j])
				return c_TRUE;
			else
				return c_FALSE;
		}
		break;
	}

	return c_FALSE;
}

//判断是否空字符串
c_INT strEmpty(c_String *sourceTar) {
	return sourceTar->length == 0;
}

//返回长度
c_INT strLength(c_String *sourceTar) {
	return sourceTar->length;
}

//返回chars
c_CHAR* strChars(c_String *sourceTar) {
	return sourceTar->chars;
}

//返回子字符串 begin end
c_String* strSubstring(c_String *sourceTar, c_INT begin, c_INT end) {
	if (end >= sourceTar->length || begin >= end)
		return C_NULL;

	c_String *newStr = C_MALLOC(c_String*, sizeof(c_String), 1);
	newStr->length = (end - begin) + 1;
	newStr->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), newStr->length + ENDCHARBIT); //这一步加多一个是结尾符的
	if (newStr->chars == C_NULL) return C_NULL;

	for (int i = begin, j = 0; i <= end; i++, j++)
		newStr->chars[j] = sourceTar->chars[i];
	newStr->chars[newStr->length] = '\0';

	return newStr;
}

//index字符
c_CHAR strCharAt(c_String *sourceTar, c_INT index) {
	if (index >= sourceTar->length)
		index = sourceTar->length - 1;

	return sourceTar->chars[index];
}

//销毁字符串
c_VOID strDestory(c_String *sourceTar) {
	C_FREE(sourceTar->chars);
	sourceTar->length = 0;
	C_FREE(sourceTar);
}