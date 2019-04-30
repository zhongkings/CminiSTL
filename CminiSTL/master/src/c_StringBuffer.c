#include "c_StringBuffer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

c_StringBuffer* strbCreate() {
	c_StringBuffer * strb = C_MALLOC(c_StringBuffer*, sizeof(c_StringBuffer), 1);

	strb->size = 0;
	strb->capacity = 10;
	strb->type = c_StringType;
	strb->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), strb->capacity);
	strb->chars[strb->size] = C_STOPEND;

	return strb;
}

c_StringBuffer* strbCreateChars(c_CHAR *chars) {
	c_StringBuffer * strb = C_MALLOC(c_StringBuffer*, sizeof(c_StringBuffer), 1);
	c_INT len = strlen(chars);
	
	strb->size = len;
	strb->capacity = len + 5;
	strb->type = c_StringType;
	strb->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), strb->capacity);

	for (c_INT i = 0; i < len; i++)
		strb->chars[i] = chars[i];
	strb->chars[strb->size] = C_STOPEND;

	return strb;
}

c_StringBuffer* strbCreateCapacity(c_INT capacity) {
	c_StringBuffer * strb = C_MALLOC(c_StringBuffer*, sizeof(c_StringBuffer), 1);
	strb->size = 0;
	strb->capacity = capacity;
	strb->type = c_StringType;
	strb->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), strb->capacity);
	strb->chars[strb->size] = C_STOPEND;

	return strb;
}

c_StringBuffer* strbCreateString(c_String *str) {
	c_StringBuffer * strb = C_MALLOC(c_StringBuffer*, sizeof(c_StringBuffer), 1);
	c_INT len = str->length;

	strb->size = len;
	strb->capacity = len + 5;
	strb->type = c_StringType;
	strb->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), strb->capacity);

	for (c_INT i = 0; i < len; i++)
		strb->chars[i] = str->chars[i];
	strb->chars[strb->size] = C_STOPEND;

	return strb;
}

c_VOID strbAppendOfChar(c_StringBuffer *sourceTar, c_CHAR value) {
	strbAppendOfChars(sourceTar, &value);
}

c_VOID strbAppendOfInt(c_StringBuffer *sourceTar, c_INT value) {
	c_CHAR ch[11];
	sprintf(ch, "%d", value);
	strbAppendOfChars(sourceTar, ch);
}

c_VOID strbAppendOfFloat(c_StringBuffer *sourceTar, c_FLOAT value) {
	c_CHAR ch[50];
	sprintf(ch, "%f", value);
	strbAppendOfChars(sourceTar, ch);
}

c_VOID strbAppendOfDouble(c_StringBuffer *sourceTar, c_DOUBLE value) {
	c_CHAR ch[50];
	sprintf(ch, "%f", value);
	strbAppendOfChars(sourceTar, ch);
}

c_VOID strbAppendOfChars(c_StringBuffer *sourceTar, c_CHAR *str) {
	c_INT len = strlen(str);

	//判断是否只剩下一个位置 多一个是结尾符
	if ((sourceTar->size + 2 + len) >= sourceTar->capacity) {
		sourceTar->capacity += len + 5; //增加len 再加5个
		c_CHAR *new_chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), sourceTar->capacity);
		strcpy(new_chars, sourceTar->chars);
		C_FREE(sourceTar->chars);
		sourceTar->chars = new_chars;
	}

	for (c_INT i = 0; i < len; i++, sourceTar->size++)
		sourceTar->chars[sourceTar->size] = str[i];
	sourceTar->chars[sourceTar->size] = C_STOPEND;		
}

c_VOID strbAppendOfCharsForlen(c_StringBuffer *sourceTar, c_CHAR *str, c_INT len) {
	//判断是否只剩下一个位置 多一个是结尾符
	if ((sourceTar->size + 2 + len) >= sourceTar->capacity) {
		sourceTar->capacity += len + 5;  //增加len 再加5个
		c_CHAR *new_chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), sourceTar->capacity);
		memcpy(new_chars, sourceTar->chars, sizeof(c_CHAR) * sourceTar->size);

		C_FREE(sourceTar->chars);
		sourceTar->chars = new_chars;
	}

	for (c_INT i = 0; i < len; i++, sourceTar->size++)
		sourceTar->chars[sourceTar->size] = str[i];

	sourceTar->chars[sourceTar->size] = C_STOPEND;
}

c_VOID strbAppendOfString(c_StringBuffer *sourceTar, c_String *str) {
	strbAppendOfCharsForlen(sourceTar, str->chars, str->length);
}

c_VOID strbAppendOfStbuffer(c_StringBuffer *sourceTar, c_StringBuffer *strb) {
	strbAppendOfCharsForlen(sourceTar, strb->chars, strb->size);
}

c_VOID strbInsertOfInt(c_StringBuffer *sourceTar, c_INT value, c_INT index) {
	c_CHAR ch[11];
	sprintf(ch, "%d", value);
	strbInsertOfChars(sourceTar, ch, index);
}

c_VOID strbInsertOfFloat(c_StringBuffer *sourceTar, c_FLOAT value, c_INT index) {
	c_CHAR ch[50];
	sprintf(ch, "%f", value);
	strbInsertOfChars(sourceTar, ch, index);
}

c_VOID strbInsertOfDouble(c_StringBuffer *sourceTar, c_DOUBLE value, c_INT index) {
	c_CHAR ch[50];
	sprintf(ch, "%f", value);
	strbInsertOfChars(sourceTar, ch, index);
}

c_VOID strbInsertOfChar(c_StringBuffer *sourceTar, c_CHAR value, c_INT index) {
	strbInsertOfChars(sourceTar, &value, index);
}

c_VOID strbInsertOfChars(c_StringBuffer *sourceTar, c_CHAR *str, c_INT index) {
	c_INT len = strlen(str);
	
	//判断是否只剩下一个位置 多一个是结尾符
	if ((sourceTar->size + 2 + len) >= sourceTar->capacity) {
		sourceTar->capacity += len + 5; //增加len 再加5个
		c_CHAR *new_chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), sourceTar->capacity);
		strcpy(new_chars, sourceTar->chars);

		C_FREE(sourceTar->chars);
		sourceTar->chars = new_chars;
	}
	for (c_INT i = sourceTar->size - 1; i >= index; i--)
		sourceTar->chars[i + len] = sourceTar->chars[i];
	for (c_INT i = index, j = 0; j < len; i++, j++, sourceTar->size++)
		sourceTar->chars[i] = str[j];
	

	sourceTar->chars[sourceTar->size] = C_STOPEND;
}

c_VOID strbInsertOfCharsForlen(c_StringBuffer *sourceTar, c_CHAR *str, c_INT len, c_INT index) {
	//判断是否只剩下一个位置 多一个是结尾符
	if ((sourceTar->size + 2 + len) >= sourceTar->capacity) {
		sourceTar->capacity += len + 5; //增加len 再加5个
		c_CHAR *new_chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), sourceTar->capacity);
		strcpy(new_chars, sourceTar->chars);

		C_FREE(sourceTar->chars);
		sourceTar->chars = new_chars;
	}
	for (c_INT i = sourceTar->size - 1; i >= index; i--)
		sourceTar->chars[i + len] = sourceTar->chars[i];
	for (c_INT i = index, j = 0; j < len; i++, j++, sourceTar->size++)
		sourceTar->chars[i] = str[j];


	sourceTar->chars[sourceTar->size] = C_STOPEND;
}

c_VOID strbInsertOfString(c_StringBuffer *sourceTar, c_String *str, c_INT index) {
	strbInsertOfCharsForlen(sourceTar, str->chars, str->length, index);
}

c_VOID strbInsertOfStbuffer(c_StringBuffer *sourceTar, c_StringBuffer *strb, c_INT index) {
	strbInsertOfCharsForlen(sourceTar, strb->chars, strb->size, index);
}

c_VOID strbDelete(c_StringBuffer *sourceTar, c_INT begin, c_INT end) {
	if (sourceTar->size == 0)
		return;
	if (begin < 0 || begin >= end)
		return;
	if (end < 0 || end >= sourceTar->size)
		return;

	c_INT len = (end - begin) + 1; // 0123456789
	for (c_INT i = begin; i <= end; i++, sourceTar->size--)
		sourceTar->chars[i] = sourceTar->chars[i + len];
	sourceTar->chars[sourceTar->size] = C_STOPEND;
}

c_VOID strbReverse(c_StringBuffer *sourceTar) {
	if (sourceTar->size == 0)
		return;

	c_INT foldlen = sourceTar->size / 2;
	for (c_INT i = 0; i < foldlen; i++) {
		c_CHAR temp = sourceTar->chars[i];
		sourceTar->chars[i] = sourceTar->chars[(sourceTar->size - i) - 1];
		sourceTar->chars[(sourceTar->size - i) - 1] = temp;
	}
}

c_String* strbString(c_StringBuffer *sourceTar) {
	if (sourceTar->size == 0)
		return C_NULL;

	c_String *str = strAssignChars(sourceTar->chars);

	return str;
}

c_String* strbSubString(c_StringBuffer *sourceTar, c_INT begin, c_INT end) {
	if (begin < 0 || begin <= end)
		return C_NULL;
	if (end < 0 || end <= sourceTar->size)
		return C_NULL;

	c_INT len = (end + begin) + 2;//包括结尾 和 结束符 +2
	c_CHAR *chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), len);
	for (c_INT i = begin, j = 0; i <= end; i++, j++)
		chars[j] = sourceTar->chars[j];
	chars[len - 1] = C_STOPEND;

	c_String *str = strAssignChars(chars);
	C_FREE(chars);
	return str;
}

c_VOID strbShrink(c_StringBuffer *sourceTar) {
	sourceTar->capacity = (sourceTar->size + 5);

	c_CHAR *new_chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), sourceTar->capacity);
	strcpy(new_chars, sourceTar->chars);

	C_FREE(sourceTar->chars);

	sourceTar->chars = new_chars;
	sourceTar->chars[sourceTar->size] = C_STOPEND;
}

c_VOID strbClear(c_StringBuffer *sourceTar) {
	C_FREE(sourceTar->chars);

	sourceTar->size = 0;
	sourceTar->capacity = 10;
	sourceTar->chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), sourceTar->capacity);
	sourceTar->chars[sourceTar->size] = C_STOPEND;
}

c_CHAR strbCharAt(c_StringBuffer *sourceTar, c_INT index) {
	if (index < 0 || index >= sourceTar->size)
		index = sourceTar->size - 1;
	c_CHAR c = sourceTar->chars[index];

	return c;
}

c_INT strbLength(c_StringBuffer *sourceTar) {
	return sourceTar->size;
}

c_INT strbCapacity(c_StringBuffer *sourceTar) {
	return sourceTar->capacity;
}

c_BOOL strbEmpty(c_StringBuffer *sourceTar) {
	return sourceTar->size == 0;
}

//使用kmp算法
c_INT strbIndexOf(c_StringBuffer *sourceTar, c_String *substr, c_INT begin);
c_INT strbIndexOfChar(c_StringBuffer *sourceTar, c_CHAR *substr, c_INT begin);
c_INT strbIndexOflast(c_StringBuffer *sourceTar, c_String *substr, c_INT begin);
c_INT strbIndexOfCharlast(c_StringBuffer *sourceTar, c_CHAR *substr, c_INT begin);

c_VOID strbDestroy(c_StringBuffer *sourceTar) {
	C_FREE(sourceTar->chars);

	sourceTar->size = 0;
	sourceTar->capacity = 0;
	sourceTar->chars = C_NULL;

	C_FREE(sourceTar);
}