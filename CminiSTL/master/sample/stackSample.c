#include "c_Stack.h"
#include "c_Algorithm.h"
#include "c_Timer.h"
#include "sample/sample.h"

c_VOID StackIntPushback(c_Stack *sourceTar, c_INT i) {
	c_INT *ptr = C_MALLOC(c_INT*, sizeof(c_INT), 1);
	*ptr = i;

	stackPushback(sourceTar, ptr);
}

c_VOID StackPrintEx(c_DATA *data) {
	if (data == C_NULL)
		return;
	printf("%d %c\n", *(c_INT*)data, *(c_INT*)data);
}

void Stackmain() {
	c_Stack *stack = stackCreate(sizeof(int));

	StackIntPushback(stack, '+');
	StackIntPushback(stack, '-');
	StackIntPushback(stack, '*');
	StackIntPushback(stack, '/');
	
	while (!stackEmpty(stack)) {
		StackPrintEx(stackPopback(stack));
	}

	printf("\nstack size: %d\n", stack->size);
}