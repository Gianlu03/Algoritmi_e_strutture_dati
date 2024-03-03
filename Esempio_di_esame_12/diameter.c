#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


void brenchDepth(const Node* t, int i, int* maxDepth) {
	if (i > *maxDepth)
		*maxDepth = i;

	if (t->right == NULL && t->left == NULL)
		return;

	if (t->left != NULL)
		brenchDepth(t->left, i + 1, maxDepth);
	if (t->right != NULL)
		brenchDepth(t->right, i + 1, maxDepth);

}

void DiameterRec(const Node* t, int i, int* maxDiameter) {
	int leftDepth = 0;
	int rightDepth = 0;

	if (t->left != NULL)
		brenchDepth(t->left, 1, &leftDepth);
	if (t->right != NULL)
		brenchDepth(t->right, 1, &rightDepth);

	int partialDiameter = 0;
	if (leftDepth > 0 && rightDepth > 0)
		partialDiameter = leftDepth + rightDepth + 1;
	else if (leftDepth == 0 && rightDepth > 0)
		partialDiameter = rightDepth + 1;
	else if (leftDepth > 0 && rightDepth == 0)
		partialDiameter = leftDepth + 1;

	if (partialDiameter > *maxDiameter)
		*maxDiameter = partialDiameter;

	if (t->left != NULL)
		DiameterRec(t->left, i+1, maxDiameter);
	if (t->right != NULL)
		DiameterRec(t->right, i+1, maxDiameter);

}

extern int Diameter(const Node* t) {
	if (TreeIsEmpty(t) || t == NULL) return 0;
	
	if (t->right == NULL && t->left == NULL) return 1;

	int maxDiameter = 0;

	DiameterRec(t, 0, &maxDiameter);

	return maxDiameter;
}

/*
int main(void) {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9,9 };
	Node* tree = TreeCreateRoot(e + 0,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 3,
				TreeCreateRoot(e + 5, NULL, NULL),
				TreeCreateRoot(e + 6, 
					TreeCreateRoot(e+10, NULL, NULL), NULL)
			),
			TreeCreateRoot(e + 4,
				TreeCreateRoot(e + 7, NULL, NULL),
				TreeCreateRoot(e + 8,
					TreeCreateRoot(e + 9, NULL, NULL),
					NULL
				)
			)
		),
		TreeCreateRoot(e + 2,NULL, NULL
		));

	int d = Diameter(tree);
	return 0;
}

*/