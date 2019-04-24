#pragma once
#include "c_DataTypedef.h"
typedef struct c_NodeStruct {
	struct c_NodeStruct *next;
	c_DATA *data;
} c_sinNode;

c_sinNode* sinNodeCreate();
c_sinNode* sinNodeCreateformData(c_DATA *data);
c_sinNode* sinNodeCreateformsinNode(c_sinNode *sourceTar);

//装载数据
c_VOID sinNodeLoadData(c_sinNode *sourceTar, c_DATA *data);
//卸载数据
c_DATA* sinNodeunLoadData(c_sinNode *sourceTar);
//directionTar链接到sourceTar后面
c_VOID sinNodeLinkback(c_sinNode *directionTar, c_sinNode *sourceTar);
//这只是交换数据不交换位置
c_VOID sinNodeSwap(c_sinNode *directionTar, c_sinNode *sourceTar);
c_VOID sinNodeClear(c_sinNode *sourceTar);

c_DATA* sinNodeDestroy(c_sinNode *sourceTar);