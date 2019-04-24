#pragma once

//Type define
typedef int            c_INT;
typedef unsigned int   c_UINT;
typedef unsigned int   c_BOOL;
typedef unsigned int   c_ERRO;
typedef float          c_FLOAT;
typedef double         c_DOUBLE;
typedef short          c_SHORT;
typedef unsigned short c_USHORT;
typedef unsigned short c_WCHAR;
typedef char           c_CHAR;
typedef unsigned char  c_BYTE;
typedef void           c_DATA;
typedef void           c_VOID;

//Fun define
typedef enum { c_VectorType, c_ListType, c_SingleListType }c_TYPE;
typedef enum { c_TRUE = 1, c_FALSE = 0, c_LEFT = 1, c_RIGHT = 2 } c_VARIAYE;
typedef enum { c_LESS = 0, c_EQUAL = 1, c_Greater = 2 } c_COMPAREVAR;
typedef c_BOOL(*c_OPEATIONFUN)(c_DATA *data_first, c_DATA *data_second, c_VARIAYE var);
typedef c_VOID(*c_EXTENDFUN)(c_DATA *data);

//macro define
#define C_NULL NULL
#define C_MALLOC(_Typeptr, _Byte, _Length) (_Typeptr)malloc(_Byte * _Length)
#define C_FREE(_Data) free(_Data)