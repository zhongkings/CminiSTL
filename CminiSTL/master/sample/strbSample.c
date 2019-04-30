#include "c_StringBuffer.h"
#include <stdio.h>

void strbSample() {
	c_StringBuffer *sb = strbCreate();
	
	strbAppendOfChars(sb, "CBAVVV");
	strbReverse(sb);
	printf("%s \n", sb->chars);
	printf("size: %d  capacity: %d\n", sb->size, sb->capacity);
}