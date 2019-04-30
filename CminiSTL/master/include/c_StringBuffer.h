#pragma once
#include "c_String.h"

typedef struct {
	c_TYPE type;
	c_CHAR *chars;
	c_INT size;
	c_INT capacity;
} c_StringBuffer;

c_StringBuffer* strbCreate();
c_StringBuffer* strbCreateChars(c_CHAR *chars);
c_StringBuffer* strbCreateCapacity(c_INT capacity);
c_StringBuffer* strbCreateString(c_String *str);

c_VOID strbAppendOfInt(c_StringBuffer *sourceTar, c_INT value);
c_VOID strbAppendOfFloat(c_StringBuffer *sourceTar, c_FLOAT value);
c_VOID strbAppendOfDouble(c_StringBuffer *sourceTar, c_DOUBLE value);
c_VOID strbAppendOfChar(c_StringBuffer *sourceTar, c_CHAR value);
c_VOID strbAppendOfChars(c_StringBuffer *sourceTar, c_CHAR *str);
c_VOID strbAppendOfCharsForlen(c_StringBuffer *sourceTar, c_CHAR *str, c_INT len);
c_VOID strbAppendOfString(c_StringBuffer *sourceTar, c_String *str);
c_VOID strbAppendOfStbuffer(c_StringBuffer *sourceTar, c_StringBuffer *strb);
c_VOID strbInsertOfInt(c_StringBuffer *sourceTar, c_INT value, c_INT index);
c_VOID strbInsertOfFloat(c_StringBuffer *sourceTar, c_FLOAT value, c_INT index);
c_VOID strbInsertOfDouble(c_StringBuffer *sourceTar, c_DOUBLE value, c_INT index);
c_VOID strbInsertOfChar(c_StringBuffer *sourceTar, c_CHAR value, c_INT index);
c_VOID strbInsertOfChars(c_StringBuffer *sourceTar, c_CHAR *str, c_INT index);
c_VOID strbInsertOfCharsForlen(c_StringBuffer *sourceTar, c_CHAR *str, c_INT len, c_INT index);
c_VOID strbInsertOfString(c_StringBuffer *sourceTar, c_String *str, c_INT index);
c_VOID strbInsertOfStbuffer(c_StringBuffer *sourceTar, c_StringBuffer *strb, c_INT index);

c_VOID strbDelete(c_StringBuffer *sourceTar, c_INT begin, c_INT end);

c_VOID strbReverse(c_StringBuffer *sourceTar);
c_String* strbString(c_StringBuffer *sourceTar);
c_String* strbSubString(c_StringBuffer *sourceTar, c_INT begin, c_INT end);
c_VOID strbShrink(c_StringBuffer *sourceTar);
c_VOID strbClear(c_StringBuffer *sourceTar);
c_CHAR strbCharAt(c_StringBuffer *sourceTar, c_INT index);
c_INT strbLength(c_StringBuffer *sourceTar);
c_INT strbCapacity(c_StringBuffer *sourceTar);
c_BOOL strbEmpty(c_StringBuffer *sourceTar);

c_INT strbIndexOf(c_StringBuffer *sourceTar, c_String *substr, c_INT begin);
c_INT strbIndexOfChar(c_StringBuffer *sourceTar, c_CHAR *substr, c_INT begin);
c_INT strbIndexOflast(c_StringBuffer *sourceTar, c_String *substr, c_INT begin);
c_INT strbIndexOfCharlast(c_StringBuffer *sourceTar, c_CHAR *substr, c_INT begin);

c_VOID strbDestroy(c_StringBuffer *sourceTar);