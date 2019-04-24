#include "c_SingleList.h"
#include "c_String.h"

c_SingleList* sinlistCreate() {
	c_SingleList *newsinList = C_MALLOC(c_SingleList*, sizeof(c_SingleList), 1);
	newsinList->type = c_SingleListType;
	newsinList->size = 0;
	newsinList->head = sinNodeCreate();
	newsinList->tail = newsinList->head;
	newsinList->head->next = newsinList->tail;

	return newsinList;
}

c_SingleList* sinlistCreateformsinList(c_SingleList *sourceTar) {
	c_SingleList *newsinList = C_MALLOC(c_SingleList*, sizeof(c_SingleList), 1);
	newsinList->type = c_SingleListType;
	newsinList->size = sourceTar->size;
	newsinList->operate = sourceTar->operate;
	newsinList->head = sinNodeCreate();
	newsinList->tail = newsinList->head;

	c_sinNode *iterator1 = sourceTar->head;
	c_sinNode *iterator2 = newsinList->head;
	while (iterator1->next != C_NULL) {
		c_sinNode *newNode = sinNodeCreateformData(iterator1->next->data);
		iterator2->next = newNode;

		iterator2 = iterator2->next;
		iterator1 = iterator1->next;
	}
	newsinList->tail = iterator2;

	return newsinList;
}

c_VOID sinlistInsert(c_SingleList *sourceTar, c_DATA *data, c_INT index) {
	if (index < 0 || index > sourceTar->size) return;
	if (index == sourceTar->size) {
		sinlistPushback(sourceTar, data);
		return;
	}

	c_sinNode *newNode = sinNodeCreateformData(data);
	c_sinNode *iterator = sourceTar->head;

	while (index) {
		iterator = iterator->next;
		index--;
	}

	c_sinNode *temp = iterator->next;
	iterator->next = newNode;
	newNode->next = temp;
	sourceTar->size++;
}

c_VOID sinlistPushback(c_SingleList *sourceTar, c_DATA *data) {
	c_sinNode *newNode = sinNodeCreateformData(data);
	sourceTar->tail->next = newNode;
	sourceTar->tail = newNode;

	sourceTar->size++;
}

c_DATA* sinlistPopback(c_SingleList *sourceTar) {
	c_sinNode *popNode = sourceTar->tail;
	c_sinNode *iterator = sourceTar->head;
	while (iterator->next != popNode) {
		iterator = iterator->next;
	}
	iterator->next = popNode->next; //相当于iterator->next = C_NULL
	sourceTar->tail = iterator;
	sourceTar->size--;

	return sinNodeDestroy(popNode);
}

c_DATA* sinlistErase(c_SingleList *sourceTar, c_INT index) {
	if (index < 0 || index >= sourceTar->size) return C_NULL;
	if (index == sourceTar->size - 1) {
		return sinlistPopback(sourceTar);
	}

	c_sinNode *iterator = sourceTar->head;
	while (index) {
		iterator = iterator->next;
		index--;
	}
	c_sinNode *delNode = iterator->next;
	iterator->next = delNode->next;
	sourceTar->size--;

	return sinNodeDestroy(delNode);
}

c_DATA* sinlistEraseOfValue(c_SingleList *sourceTar, c_DATA *data, c_INT begin) {
	if (begin < 0 || begin >= sourceTar->size - 1) return C_NULL;

	c_sinNode *iterator = sourceTar->head;
	while (iterator->next != C_NULL) {
		if (sourceTar->operate(iterator->next->data, data, c_EQUAL))
			break;
		iterator = iterator->next;
	}

	if (iterator->next == C_NULL)
		return C_NULL;

	c_sinNode *delNode = iterator->next;
	iterator->next = delNode->next;
	sourceTar->size--;

	//如果找到是最后一位，就将尾指针指向它
	if (iterator->next == C_NULL)
		sourceTar->tail = iterator;

	return sinNodeDestroy(delNode);
}

c_BOOL sinlistEnpty(c_SingleList *sourceTar) {
	return sourceTar->size == 0;
}

c_INT  sinlistLength(c_SingleList *sourceTar) {
	return sourceTar->size;
}

c_BOOL sinlistContains(c_SingleList *sourceTar, c_DATA *data) {
	if (sourceTar->size == 0 || data == C_NULL) return -1;

	c_sinNode *iterator = sourceTar->head;
	while (iterator->next != C_NULL) {
		if (sourceTar->operate(iterator->next->data, data, c_EQUAL))
			return c_TRUE;

		iterator = iterator->next;
	}

	return c_FALSE;
}

c_VOID sinlistCopy(c_SingleList *directionTar, c_SingleList *sourceTar) {
	if (sourceTar->size == 0) return;
	if (directionTar->size > 0) sinlistClear(directionTar);

	c_sinNode *iteratorS = sourceTar->head;
	while (iteratorS->next != C_NULL) {
		sinlistPushback(directionTar, iteratorS->next->data);
		iteratorS = iteratorS->next;
	}
}

c_VOID sinlistLink(c_SingleList *directionTar, c_SingleList *sourceTar, c_INT index) {
	if (sourceTar->size == 0) return;
	if (index < 0 || index >= sourceTar->size) return;

	c_sinNode *iteratorS = sourceTar->head;
	while (index) {
		iteratorS = iteratorS->next;
		index--;
	}

	while (iteratorS->next != C_NULL) {
		sinlistPushback(directionTar, iteratorS->next->data);
		iteratorS = iteratorS->next;
	}
}

c_VOID sinlistClear(c_SingleList *sourceTar) {
	c_sinNode *iterator = sourceTar->head;
	while (iterator->next != C_NULL) {
		c_sinNode *delNode = iterator->next;
		iterator->next = delNode->next;
		sinNodeDestroy(delNode);
		sourceTar->size--;
	}

	sourceTar->tail = sourceTar->head;
}

c_DATA* sinlistAt(c_SingleList *sourceTar, c_INT index) {
	if (index < 0 || index >= sourceTar->size)
		index = sourceTar->size - 1;

	c_sinNode *iterator = sourceTar->head;
	while (index) {
		iterator = iterator->next;
		index--;
	}

	return iterator->next->data;
}

c_DATA* sinlistFront(c_SingleList *sourceTar) {
	c_sinNode *delNode = sourceTar->head->next;
	sourceTar->head->next = delNode->next;

	if (sourceTar->head->next == C_NULL)
		sourceTar->tail = sourceTar->head;
	sourceTar->size--;

	return sinNodeDestroy(delNode);
}
c_DATA* sinlistBack(c_SingleList *sourceTar) {
	return sinlistPopback(sourceTar);
}

c_VOID sinlistExtend(c_SingleList *sourceTar, c_EXTENDFUN efun) {
	c_sinNode *iterator = sourceTar->head;

	while (iterator->next != C_NULL) {
		efun(iterator->next->data);
		iterator = iterator->next;
	}
}

//Node
c_sinNode* sinlistAtNode(c_SingleList *sourceTar, c_INT index) {
	if (index < 0 || index >= sourceTar->size)
		index = sourceTar->size - 1;

	c_sinNode *iterator = sourceTar->head;
	while (index) {
		iterator = iterator->next;
		index--;
	}

	return iterator->next;
}

c_sinNode* sinlistFrontNode(c_SingleList *sourceTar) {
	c_sinNode *delNode = sourceTar->head->next;
	sourceTar->head->next = delNode->next;
	delNode->next = C_NULL;

	if (sourceTar->head->next == C_NULL)
		sourceTar->tail = sourceTar->head;
	sourceTar->size--;

	return	delNode;
}

c_sinNode* sinlistBackNode(c_SingleList *sourceTar) {
	c_sinNode *popNode = sourceTar->tail;
	c_sinNode *iterator = sourceTar->head;
	while (iterator->next != popNode) {
		iterator = iterator->next;
	}
	iterator->next = popNode->next; //相当于iterator->next = C_NULL
	popNode->next = C_NULL;
	sourceTar->tail = iterator;
	sourceTar->size--;

	return popNode;
}

c_VOID sinlistDestroy(c_SingleList *sourceTar) {
	c_sinNode *iterator = sourceTar->head;
	while (iterator->next != C_NULL) {
		c_sinNode *delNode = iterator->next;
		iterator->next = delNode->next;
		sinNodeDestroy(delNode);
		sourceTar->size--;
	}

	sinNodeDestroy(sourceTar->head);
	sourceTar->size = 0;
	sourceTar->head = C_NULL;
	sourceTar->tail = C_NULL;
	sourceTar->operate = C_NULL;

	C_FREE(sourceTar);
}