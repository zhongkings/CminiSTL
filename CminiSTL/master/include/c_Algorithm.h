#pragma once
#include "c_DataTypedef.h"

//Search
c_INT Sequential_Search(c_DATA *datapack, c_DATA *key);
c_INT vecBinary_Search(c_DATA *datapack, c_DATA *key);

//Sort
c_VOID BubbleSort(c_DATA *datapack, c_COMPAREVAR compvar);
c_VOID SelectSort(c_DATA *datapack, c_COMPAREVAR compvar);
c_VOID InsertSort(c_DATA *datapack, c_COMPAREVAR compvar);
c_VOID ShellSort(c_DATA *datapack, c_COMPAREVAR compvar);