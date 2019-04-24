#include "Node/c_douNode.h"
#include <string.h>
#include <stdlib.h>

c_douNode* douNodeCreate() {
	c_douNode *newdouNode = C_MALLOC(c_douNode*, sizeof(c_douNode), 1);
	newdouNode->left = C_NULL;
	newdouNode->right = C_NULL;
	newdouNode->data = C_NULL;

	return newdouNode;
}

c_douNode* douNodeCreateformData(c_DATA *data) {
	c_douNode *newdouNode = C_MALLOC(c_douNode*, sizeof(c_douNode), 1);
	newdouNode->left = C_NULL;
	newdouNode->right = C_NULL;
	newdouNode->data = data;

	return newdouNode;
}

c_douNode* douNodeCreateformdouNode(c_douNode *sourceTar) {
	c_douNode *newdouNode = C_MALLOC(c_douNode*, sizeof(c_douNode), 1);
	newdouNode->left = sourceTar->left;
	newdouNode->right = sourceTar->right;
	newdouNode->data = sourceTar->data;

	return newdouNode;
}

c_VOID douNodeLoadData(c_douNode *sourceTar, c_DATA *data) {
	sourceTar->data = data;
}

c_VOID douNodeLinkfront(c_douNode *directionTar, c_douNode *sourceTar) {
	directionTar->left = sourceTar->left;
	sourceTar->left = directionTar;

	directionTar->right = sourceTar;
	if (directionTar->left != C_NULL)
	directionTar->left->right = directionTar;
}

c_VOID douNodeLinkback(c_douNode *directionTar, c_douNode *sourceTar) {
	directionTar->right = sourceTar->right;
	sourceTar->right = directionTar;

	directionTar->left = sourceTar;
	if (directionTar->right != C_NULL)
		directionTar->right->left = directionTar;
}

c_VOID douNodeSwap(c_douNode *directionTar, c_douNode *sourceTar) {
	c_DATA *temp = directionTar->data;
	directionTar->data = sourceTar->data;
	sourceTar->data = temp;
}

c_VOID douNodeClear(c_douNode *sourceTar) {
	if (sourceTar->data != C_NULL)
		C_FREE(sourceTar->data);

	sourceTar->left = C_NULL;
	sourceTar->right = C_NULL;
}

c_VOID douNodeUnlink(c_douNode *sourceTar) {
	sourceTar->left->right = sourceTar->right;
	sourceTar->right->left = sourceTar->left;
}

c_VOID douNodeDestroy(c_douNode *sourceTar) {
	if (sourceTar->data != C_NULL)
		C_FREE(sourceTar->data);

	sourceTar->left = C_NULL;
	sourceTar->right = C_NULL;

	C_FREE(sourceTar);
}

c_VOID douNodeDestroyNodestData(c_douNode *sourceTar) {
	sourceTar->left = C_NULL;
	sourceTar->right = C_NULL;

	C_FREE(sourceTar);
}