#pragma once
#include"c_DataTypedef.h"

typedef struct c_douNodeStruct {
	struct c_douNodeStruct *right;
	struct c_douNodeStruct *left;
	c_DATA *data;
} c_douNode;

c_douNode* douNodeCreate();
c_douNode* douNodeCreateformData(c_DATA *data);
c_douNode* douNodeCreateformdouNode(c_douNode *sourceTar);

//装载数据
c_VOID douNodeLoadData(c_douNode *sourceTar, c_DATA *data);
//directionTar链接到sourceTar前面
c_VOID douNodeLinkfront(c_douNode *directionTar, c_douNode *sourceTar);
//directionTar链接到sourceTar后面
c_VOID douNodeLinkback(c_douNode *directionTar, c_douNode *sourceTar);
//这只是交换数据不交换位置
c_VOID douNodeSwap(c_douNode *directionTar, c_douNode *sourceTar);
c_VOID douNodeClear(c_douNode *sourceTar);
//脱链
c_VOID douNodeUnlink(c_douNode *sourceTar);

c_VOID douNodeDestroy(c_douNode *sourceTar);
//释放结点但是不释放数据
c_VOID douNodeDestroyNodestData(c_douNode *sourceTar);