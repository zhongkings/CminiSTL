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

//װ������
c_VOID douNodeLoadData(c_douNode *sourceTar, c_DATA *data);
//directionTar���ӵ�sourceTarǰ��
c_VOID douNodeLinkfront(c_douNode *directionTar, c_douNode *sourceTar);
//directionTar���ӵ�sourceTar����
c_VOID douNodeLinkback(c_douNode *directionTar, c_douNode *sourceTar);
//��ֻ�ǽ������ݲ�����λ��
c_VOID douNodeSwap(c_douNode *directionTar, c_douNode *sourceTar);
c_VOID douNodeClear(c_douNode *sourceTar);
//����
c_VOID douNodeUnlink(c_douNode *sourceTar);

c_VOID douNodeDestroy(c_douNode *sourceTar);
//�ͷŽ�㵫�ǲ��ͷ�����
c_VOID douNodeDestroyNodestData(c_douNode *sourceTar);