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

//�����ַ���
c_String* strLinks(c_String *sourceTar1, c_String *sourceTar2);
//����ָ���ַ� ���ظ��ַ�����һ�γ��ֵ�����
c_INT strValueOf(c_String *sourceTar, c_String *subTar,c_INT begin);
c_INT strValueOfChar(c_String *sourceTar, c_CHAR *subTar,c_INT begin);
//����ָ���ַ� ���ظ��ַ������������һ�γ��ֵ����� ʹ��KMP�㷨����
c_INT strValueOfEnd(c_String *sourceTar, c_String *subTar, c_INT begin);
c_INT strValueOfCharEnd(c_String *sourceTar, c_CHAR *subTar, c_INT begin);
//�Ա��ַ���
c_BOOL strEqual(c_String *str1, c_String *str2);
c_BOOL strEqualChar(c_String *str1, c_CHAR *str2);
c_BOOL strOperate(c_String *str1, c_String *str2, c_COMPAREVAR compvar);
c_BOOL strOperateChar(c_String *str1, c_CHAR *str2, c_COMPAREVAR compvar);
//�ж��Ƿ���ַ���
c_INT strEmpty(c_String *sourceTar);
//���س���
c_INT strLength(c_String *sourceTar);
//����chars
c_CHAR* strChars(c_String *sourceTar);
//�������ַ��� begin end
c_String* strSubstring(c_String *sourceTar, c_INT begin, c_INT end);
//index�ַ�
c_CHAR strCharAt(c_String *sourceTar, c_INT index);
//�����ַ���
c_VOID strDestory(c_String *sourceTar);