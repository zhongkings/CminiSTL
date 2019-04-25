#include "c_Algorithm.h"
#include "c_ArrList.h"
#include "c_List.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static c_INT vecSequential_Search(c_ArrList *vec, c_DATA *key) {
	c_INT i = 0;
	vec->elements[vec->size] = key;

	while (!vec->operate(vec->elements[i], key, c_EQUAL)) {
		i++;
	}

	vec->elements[vec->size] = C_NULL;
	if (i >= vec->size)
		i = 0;

	return i;
}
static c_INT listSequential_Search(c_List *list, c_DATA *key) {
	c_INT i = 0;
	list->tail->data = key;

	c_douNode *iterator = list->head->right;
	while (!list->operate(iterator->data,key, c_EQUAL)) {
		iterator = iterator->right;
		i++;
	}

	list->tail->data = C_NULL;
	if ( i >= list->size)
		i = 0;

	return i;
}
c_INT Sequential_Search(c_DATA *datapack, c_DATA *key) {
	c_TYPE antype = -1;
	c_INT search_value = 0;
	memcpy(&antype, datapack, sizeof(c_TYPE));
	
	switch (antype) {
	case c_VectorType:
		search_value = vecSequential_Search(datapack, key);
		break;
	case c_ListType:
		search_value = listSequential_Search(datapack, key);
		break;
	default:
		break;
	}

	return search_value;
}
c_INT vecBinary_Search(c_DATA *datapack, c_DATA *key) {
	c_ArrList *vec = (c_ArrList*)datapack;

	c_INT low = 0;
	c_INT height = vec->size - 1;
	c_INT mid = 0;
	c_INT find = 0;
	while (low < vec->size) {
		mid = (low + height) / 2;
		if (vec->operate(vec->elements[mid], key, c_Greater))
			height = mid - 1;
		else if (vec->operate(vec->elements[mid], key, c_LESS))
			low = mid + 1;
		else {
			return find;
		}
	}

	return -1;
}

//BubbleSort
static c_VOID vecBubbleSort(c_ArrList *vec, c_COMPAREVAR compvar) {
	c_INT i, j;
	c_BOOL flag = c_TRUE;
	for (i = 0; i < vec->size && flag; i++) {
		flag = c_FALSE;
		for (j = vec->size - 2; j >= i; j--) {
			if (!vec->operate(vec->elements[j], vec->elements[j + 1], compvar)) {
				c_DATA *tempdata = vec->elements[j];
				vec->elements[j] = vec->elements[j + 1];
				vec->elements[j + 1] = tempdata;
				flag = c_TRUE;
			}
		}
	}
}
static c_VOID listBubbleSort(c_List *list, c_COMPAREVAR compvar) {
	c_BOOL flag = c_TRUE;
	c_douNode *i_swapNode;
	c_douNode *j_swapNode;

	for (i_swapNode = list->head; i_swapNode != list->tail && flag; i_swapNode = i_swapNode->right) {
		flag = c_FALSE;
		for (j_swapNode = list->tail->left->left; j_swapNode != i_swapNode; j_swapNode = j_swapNode->left) {
			if (!list->operate(j_swapNode->data, j_swapNode->right->data, compvar)) {
				c_DATA *temp = j_swapNode->data;
				j_swapNode->data = j_swapNode->right->data;
				j_swapNode->right->data = temp;
				flag = c_TRUE;
			}
		}
	}
}
c_VOID BubbleSort(c_DATA *datapack, c_COMPAREVAR compvar) {
	c_TYPE antype = -1;
	memcpy(&antype, datapack, sizeof(c_TYPE));

	switch (antype) {
	case c_VectorType:
		vecBubbleSort(datapack, compvar);
		break;
	case c_ListType:
		listBubbleSort(datapack, compvar);
		break;
	default:
		break;
	}
}

//SelectSort
static c_VOID vecSelectSort(c_ArrList *vec, c_COMPAREVAR compvar) {
	c_INT i, j, comp;
	for (i = 0; i < vec->size - 1; i++) {
		comp = i;
		for (j = i + 1; j < vec->size; j++) {
			if (!vec->operate(vec->elements[comp], vec->elements[j], compvar)) {
				comp = j;
			}
		}

		if (i != comp) {
			c_DATA *temp = vec->elements[i];
			vec->elements[i] = vec->elements[comp];
			vec->elements[comp] = temp;
		}
	}
}
static c_VOID listSelectSort(c_List *list, c_COMPAREVAR compvar) {
	c_douNode *i_swapNode;
	c_douNode *j_swapNode;
	c_douNode *comp_swapNode = list->tail;

	for (i_swapNode = list->head->right; i_swapNode != list->tail->left; i_swapNode = i_swapNode->right) {
		comp_swapNode = i_swapNode;

		for (j_swapNode = i_swapNode->right; j_swapNode != list->tail; j_swapNode = j_swapNode->right) {
			if (!list->operate(comp_swapNode->data, j_swapNode->data, compvar)) {
				comp_swapNode = j_swapNode;
			}
		}

		if (comp_swapNode != i_swapNode) {
			c_DATA *temp = comp_swapNode->data;
			comp_swapNode->data = i_swapNode->data;
			i_swapNode->data = temp;
		}
	}
}
c_VOID SelectSort(c_DATA *datapack, c_COMPAREVAR compvar) {
	c_TYPE antype = -1;
	memcpy(&antype, datapack, sizeof(c_TYPE));

	switch (antype) {
	case c_VectorType:
		vecSelectSort(datapack, compvar);
		break;
	case c_ListType:
		listSelectSort(datapack, compvar);
		break;
	default:
		break;
	}
}

//InsertSort
static c_VOID vecInsertSort(c_ArrList *vec, c_COMPAREVAR compvar) {
	c_INT i, j, flag = vec->size;

	for (i = vec->size - 2; i >= 0; i--) {
		if (!vec->operate(vec->elements[i], vec->elements[i + 1], compvar)) {
			vec->elements[flag] = vec->elements[i];

			for (j = i + 1; vec->operate(vec->elements[j], vec->elements[flag], compvar); j++) {
				vec->elements[j - 1] = vec->elements[j];
			}

			vec->elements[j - 1] = vec->elements[flag];
		}
	}
}
static c_VOID listInsertSort(c_List *list, c_COMPAREVAR compvar) {
	c_douNode *i_swapNode;
	c_douNode *j_swapNode;
	c_douNode *comp_swapNode = list->tail;

	for (i_swapNode = list->tail->left->left; i_swapNode != list->head; i_swapNode = i_swapNode->left) {
		if (!list->operate(i_swapNode->data, i_swapNode->right->data, compvar)) {
			comp_swapNode->data = i_swapNode->data;
			for (j_swapNode = i_swapNode->right; list->operate(j_swapNode->data, comp_swapNode->data, compvar); j_swapNode = j_swapNode->right) {
				j_swapNode->left->data = j_swapNode->data;
			}
			j_swapNode->left->data = comp_swapNode->data;
		}
	}

	comp_swapNode->data = C_NULL;
}
c_VOID InsertSort(c_DATA *datapack, c_COMPAREVAR compvar) {
	c_TYPE antype = -1;
	memcpy(&antype, datapack, sizeof(c_TYPE));

	switch (antype) {
	case c_VectorType:
		vecInsertSort(datapack, compvar);
		break;
	case c_ListType:
		listInsertSort(datapack, compvar);
		break;
	default:
		break;
	}
}

//ShellSort
static c_VOID vecShellSort(c_ArrList *vec, c_COMPAREVAR compvar) {
	c_INT i, j;
	c_INT increment = vec->size;
	c_DATA *comp = C_NULL;
	do {
		increment = (increment / 3) + 1;
		for (i = increment; i < vec->size; i++) {
			if (vec->operate(vec->elements[i], vec->elements[i - increment], compvar)) {
				comp = vec->elements[i];
				for (j = i - increment; j >= 0 && !vec->operate(vec->elements[j], comp, compvar); j -= increment)
					vec->elements[j + increment] = vec->elements[j];
				vec->elements[j + increment] = comp;
			}
			
		}
	} while (increment > 1);
}
static c_VOID listShellSort(c_List *list, c_COMPAREVAR compvar) {
	c_douNode **arr_douNode = C_MALLOC(c_douNode**, sizeof(c_douNode*), list->size);
	c_douNode *iterator = list->head->right;
	for (c_INT index = 0; index < list->size; index++, iterator = iterator->right)
		arr_douNode[index] = iterator;

	c_INT i, j, comp;
	c_INT increment = list->size;
	do
	{
		increment = (increment / 3) + 1;
		for (i = increment; i < list->size; i++) {
			if (list->operate(arr_douNode[i]->data, arr_douNode[i - increment]->data, compvar)) {
				comp = i;
				for (j = i - increment; j >= 0 && !list->operate(arr_douNode[j]->data, arr_douNode[comp]->data, compvar); j -= increment)
					arr_douNode[j + increment]->data = arr_douNode[comp]->data;
				arr_douNode[j + increment]->data = arr_douNode[comp]->data;
			}
		}
	} while (increment > 1);

	C_FREE(arr_douNode);
}
c_VOID ShellSort(c_DATA *datapack, c_COMPAREVAR compvar) {
	c_TYPE antype = -1;
	memcpy(&antype, datapack, sizeof(c_TYPE));

	switch (antype) {
	case c_VectorType:
		vecShellSort(datapack, compvar);
		break;
	default:
		break;
	}
}

