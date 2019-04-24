#include "c_List.h"
#include <stdlib.h>
#include <stdio.h>

c_List* listCreate() {
	c_List *newList = C_MALLOC(c_List*, sizeof(c_List), 1);

	newList->type = c_ListType;

	newList->size = 0;
	newList->operate = C_NULL;
	newList->head = douNodeCreate();
	newList->tail = douNodeCreate();

	douNodeLinkback(newList->tail, newList->head);
	
	return newList;
}

c_List* listCreateformList(c_List *sourceTar) {
	c_List *newList = C_MALLOC(c_List*, sizeof(c_List), 1);

	newList->type = c_ListType;

	newList->size = sourceTar->size;
	newList->operate = sourceTar->operate;
	newList->head = douNodeCreate();
	newList->tail = douNodeCreate();

	douNodeLinkback(newList->tail, newList->head);
	douNodeLinkfront(newList->head, newList->tail);

	//it add sourceTar elements
	c_douNode *iterator = sourceTar->head;
	while (iterator->right != sourceTar->tail) {
		iterator = iterator->right;
		c_douNode *newNode = douNodeCreateformData(iterator->data);
		douNodeLinkfront(newNode, newList->tail);
	}

	return newList;
}

c_VOID listInsert(c_List *sourceTar, c_DATA *data, c_INT index) {
	if (index < 0 || index >= sourceTar->size) return;

	c_douNode *newNode = douNodeCreate();
	douNodeLoadData(newNode, data);

	c_INT decindex = index;
	c_douNode *iterator = sourceTar->head;
	while (decindex) {
		iterator = iterator->right;
		decindex--;
	}

	douNodeLinkback(newNode, iterator);
	sourceTar->size++;
}

c_VOID listPushback(c_List *sourceTar, c_DATA *data) {
	c_douNode *newNode = douNodeCreate();
	douNodeLoadData(newNode, data);
	douNodeLinkfront(newNode, sourceTar->tail);

	sourceTar->size++;
}

c_DATA* listPopback(c_List *sourceTar) {
	if (sourceTar->size == 0) return C_NULL;

	c_douNode *delNode = sourceTar->tail->left;
	douNodeUnlink(delNode);
	douNodeDestroy(delNode);

	sourceTar->size--;
	return C_NULL;
}

c_VOID listErase(c_List *sourceTar, c_INT index) {
	if (sourceTar->size == 0) return;
	if (index < 0 || index >= sourceTar->size) return;

	c_douNode *iterator = sourceTar->head;
	while (index) {
		iterator = iterator->right;
		index--;
	}

	iterator = iterator->right;
	douNodeUnlink(iterator);
	douNodeDestroy(iterator);

	sourceTar->size--;
}

c_VOID listEraseOfValue(c_List *sourceTar, c_DATA *data, c_INT begin) {
	if (sourceTar->size == 0) return;
	if (begin < 0 || begin >= sourceTar->size) return;

	c_douNode *iterator = sourceTar->head;
	for (int i = 0; i < begin; i++) 
		iterator = iterator->right;
	for (int i = begin; i < sourceTar->size; i++) {
		if (sourceTar->operate(iterator->data, data, c_EQUAL)) {
			douNodeUnlink(iterator);
			douNodeDestroy(iterator);
			sourceTar->size--;
			break;
		}
		iterator = iterator->right;
	}
}

c_BOOL listEmpty(c_List *sourceTar) {
	return sourceTar->size == 0;
}

c_INT listLength(c_List *sourceTar) {
	return sourceTar->size;
}

c_BOOL listContains(c_List *sourceTar, c_DATA *data) {
	if (sourceTar->size == 0 || data == C_NULL)
		return -1;

	c_douNode *iteratorHead = sourceTar->head->right;
	c_douNode *iteratorTail = sourceTar->tail->left;
	c_BOOL flag = c_TRUE;
	while (flag) {
		if (iteratorHead == iteratorTail || (iteratorHead->right == iteratorTail && iteratorTail->left == iteratorHead))
			flag = c_FALSE;
		
		if (sourceTar->operate(iteratorHead->data, data, c_EQUAL) || sourceTar->operate(iteratorTail->data, data, c_EQUAL))
			return c_TRUE;

		iteratorHead = iteratorHead->right;
		iteratorTail = iteratorTail->left;
	}

	return c_FALSE;
}

c_VOID listCopy(c_List *directionTar, c_List *sourceTar) {
	if (directionTar->size != 0) {
		listClear(directionTar);
	}

	c_douNode *iterator = sourceTar->head;
	while (iterator->right != sourceTar->tail) {
		iterator = iterator->right;
		c_douNode *newNode = douNodeCreateformData(iterator->data);
		douNodeLinkfront(newNode, directionTar->tail);

		directionTar->size++;
	}

	directionTar->operate = sourceTar->operate;
}

c_VOID listLink(c_List *directionTar, c_List *sourceTar, c_INT index) {
	c_douNode *d_iterator = directionTar->head;
	c_douNode *s_iterator_h = sourceTar->head->right;
	c_douNode *s_iterator_t = sourceTar->tail->left;

	while (d_iterator->right != directionTar->tail && index) {
		d_iterator = d_iterator->right;
		index--;
	}
	c_douNode *tempNode = d_iterator->right;

	directionTar->size += sourceTar->size;
	d_iterator->right = s_iterator_h;
	s_iterator_h->left = d_iterator;
	tempNode->left = s_iterator_t;
	s_iterator_t->right = tempNode;

	sourceTar->size = 0;
	sourceTar->operate = C_NULL;
	douNodeDestroy(sourceTar->head);
	douNodeDestroy(sourceTar->tail);
	C_FREE(sourceTar);
}

c_VOID listClear(c_List *sourceTar) {
	c_douNode *iterator = sourceTar->head;
	while (iterator->right != sourceTar->tail) {
		c_douNode *delNode = iterator->right;
		douNodeUnlink(delNode);
		douNodeDestroy(delNode);
		sourceTar->size--;
	}
}

c_DATA* listAt(c_List *sourceTar, c_INT index) {
	if (sourceTar->size == 0) return C_NULL;
	if (index < 0 || index >= sourceTar->size) return C_NULL;

	c_douNode *iterator = sourceTar->head;
	while (index && iterator->right != sourceTar->tail) {
		iterator = iterator->right;
		index--;
	}

	return iterator->right->data;
}

c_DATA* listFront(c_List *sourceTar) {
	if (sourceTar->size == 0) return C_NULL;
	c_douNode *delNode = sourceTar->head->right;
	c_DATA *backData = delNode->data;
	douNodeUnlink(delNode);
	douNodeDestroyNodestData(delNode);

	sourceTar->size--;

	return backData;
}

c_DATA* listBack(c_List *sourceTar) {
	if (sourceTar->size == 0) return C_NULL;
	c_douNode *delNode = sourceTar->tail->left;
	c_DATA *backData = delNode->data;
	douNodeUnlink(delNode);
	douNodeDestroyNodestData(delNode);

	sourceTar->size--;

	return backData;
}

c_VOID  listExtend(c_List *sourceTar, c_EXTENDFUN efun) {
	c_douNode *iterator = sourceTar->head;
	while (iterator->right != sourceTar->tail) {
		iterator = iterator->right;
		efun(iterator->data);
	}
}

//Node
c_douNode* listAtNode(c_List *sourceTar, c_INT index) {
	if (sourceTar->size == 0) return C_NULL;
	if (index < 0 || index >= sourceTar->size) return C_NULL;

	c_douNode *iterator = sourceTar->head;
	while (index && iterator->right != sourceTar->tail) {
		iterator = iterator->right;
		index--;
	}

	return iterator->right;
}

c_douNode* listFrontNode(c_List *sourceTar) {
	if (sourceTar->size == 0) return C_NULL;
	c_douNode *backNode = sourceTar->head->right;
	douNodeUnlink(backNode);

	sourceTar->size--;

	return backNode;
}

c_douNode* listBackNode(c_List *sourceTar) {
	if (sourceTar->size == 0) return C_NULL;
	c_douNode *backNode = sourceTar->tail->left;
	douNodeUnlink(backNode);

	sourceTar->size--;

	return backNode;
}

c_VOID listDestroy(c_List *sourceTar) {
	c_douNode *iterator = sourceTar->head;
	while (iterator->right != sourceTar->tail) {
		c_douNode *delNode = iterator->right;
		douNodeUnlink(delNode);
		douNodeDestroy(delNode);
		sourceTar->size--;
	}

	douNodeDestroy(sourceTar->head);
	douNodeDestroy(sourceTar->tail);
	sourceTar->operate = C_NULL;
	C_FREE(sourceTar);
}