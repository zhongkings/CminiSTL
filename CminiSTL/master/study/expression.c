#include "ZUCC_DataStructs.h"
#include "c_Stack.h"
#include "c_String.h"
#include "c_ArrList.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
//vector
c_CHAR* vecGetChars(c_ArrList *vec) {
	c_CHAR *chars = C_MALLOC(c_CHAR*, sizeof(c_CHAR), vec->size + 1);
	for (int i = 0; i < vec->size; i++)
		chars[i] = *(c_CHAR*)vec->elements[i];
	chars[vec->size] = '\0';

	return chars;
}

//util
static int CharToInt(char c) {
	switch (c) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	}

	return -1;
}

static int numlen(const char *str) {
	char c;
	int len = 0;
	while ((c = (*str++)) && c != '0') {
		int value = CharToInt(c);

		if (value >= 0 || c == '-' || c == '.')
			len++;
	}

	return len;
}

double StringToNumber(char *c) {
	int len = numlen(c);         //数值位数
	double result = 0;           //结果
	int decimals = 0;            //小数位数
	c_BOOL negativity = c_FALSE; //判断是否负值
	for (int i = len - 1, j = 0; i >= 0; i--, j++) {
		int value = CharToInt(c[j]);

		if (value > 0) {
			value *= pow(10, i);
		} else if (c[j] == '.') {
			decimals = ++i;
			continue;
		}
		else if (c[j] == '-') {
			negativity = c_TRUE;
			++i;
			continue;
		}

		result += value;
	}

	for (int d = 0; d < decimals; d++)
		result /= 10.0f;
	
	if (negativity)
		result = -result;

	return result;
}

//calculate 中缀表达式转后缀表达式
struct c_String* calculateValue(char *ex) {
	c_Stack *stack = stackCreate();
	c_ArrList *charV = arrCreate();
	int len = strlen(ex);

	//数字就输出
	//符号进栈直遇到跟大的弹出计算
	
	for (int i = 0; i < len; i++) {
		//判断是否数字
		if (CharToInt(ex[i]) >= 0 || ex[i] == '.') {
			arrPushback(charV, &ex[i]);
		}
		else if (!arrEmpty(charV) ) {
			c_CHAR *chars = vecGetChars(charV);
			c_String *str = strAssignChars(chars);
			stackPushback(stack, str);
			C_FREE(chars);
			arrClear(charV);
		}
	}

	while (!stackEmpty(stack)){
		printf("value: %s\n", ((c_String*)stackPopback(stack))->chars);
	}

	return C_NULL;
}