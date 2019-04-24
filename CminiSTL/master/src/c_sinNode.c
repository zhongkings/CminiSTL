#pragma once
#include "Node/c_sinNode.h"
#include <stdlib.h>
#include <string.h>

c_sinNode* sinNodeCreate() {
	c_sinNode *newsinNode = C_MALLOC(c_sinNode*, sizeof(c_sinNode), 1);
	newsinNode->next = C_NULL;
	newsinNode->data = C_NULL;

	return newsinNode;
}
c_sinNode* sinNodeCreateformData(c_DATA *data) {
	c_sinNode *newsinNode = C_MALLOC(c_sinNode*, sizeof(c_sinNode), 1);
	newsinNode->next = C_NULL;
	newsinNode->data = data;

	return newsinNode;
}
c_sinNode* sinNodeCreateformsinNode(c_sinNode *sourceTar) {
	c_sinNode *newsinNode = C_MALLOC(c_sinNode*, sizeof(c_sinNode), 1);
	newsinNode->next = sourceTar->next;
	newsinNode->data = sourceTar->data;

	return newsinNode;
}

//装载数据
c_VOID sinNodeLoadData(c_sinNode *sourceTar, c_DATA *data) {
	sourceTar->data = data;
}

//卸载数据
c_DATA* sinNodeunLoadData(c_sinNode *sourceTar) {
	c_DATA *data = sourceTar->data;
	sourceTar->data = C_NULL;

	return data;
}

//directionTar链接到sourceTar后面
c_VOID sinNodeLinkback(c_sinNode *directionTar, c_sinNode *sourceTar) {
	c_sinNode *tempNode = sourceTar->next;
	directionTar->next = tempNode;
	sourceTar->next = directionTar;
}

//这只是交换数据不交换位置
c_VOID sinNodeSwap(c_sinNode *directionTar, c_sinNode *sourceTar) {
	c_DATA *tempData = directionTar->data;
	directionTar->data = sourceTar->data;
	sourceTar->data = tempData;
}

c_VOID sinNodeClear(c_sinNode *sourceTar) {
	if (sourceTar->data != C_NULL)
		C_FREE(sourceTar->data);

	sourceTar->next = C_NULL;
}

c_DATA* sinNodeDestroy(c_sinNode *sourceTar) {
	c_DATA *data = sourceTar->data;

	sourceTar->next = C_NULL;
	sourceTar->data = C_NULL;
	C_FREE(sourceTar);

	return data;
}
