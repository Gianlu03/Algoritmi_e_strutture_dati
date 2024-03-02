#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<stdint.h>

bool TreeContainsNode(const Node* tree, const Node* node) {
	if (TreeIsEmpty(tree) || tree == NULL)
		return false;
	
	if (tree == node)
		return true;

	if (tree->left == NULL && tree->right == NULL)
		return false;

	if(tree->left != NULL && tree->right != NULL)
		return TreeContainsNode(tree->left, node) || TreeContainsNode(tree->right, node);
	
	if (tree->left != NULL && tree->right == NULL)
		return TreeContainsNode(tree->left, node);

	if (tree->left == NULL && tree->right != NULL)
		return TreeContainsNode(tree->right, node);

}

void LowestCommonAncestorRec(const Node* t, const Node* n1, const Node* n2, int i, Node** ancestor, int *depthAncestor) {
	if (TreeContainsNode(t, n1) && TreeContainsNode(t, n2) && i > *depthAncestor) {
		*ancestor = t;
		*depthAncestor = i;
	}

	if (t->left != NULL)
		LowestCommonAncestorRec(t->left, n1, n2, i + 1, ancestor, depthAncestor);
	if (t->right != NULL)
		LowestCommonAncestorRec(t->right, n1, n2, i + 1, ancestor, depthAncestor);

}

Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {
	if (t == NULL || TreeIsEmpty(t))
		return NULL;

	if (!TreeContainsNode(t, n1) || !TreeContainsNode(t, n2))
		return NULL;

	Node** ancestor = t; //la radice lo è sicuramente
	int depthAncestor = 0;
	LowestCommonAncestorRec(t, n1, n2, 0, &ancestor, &depthAncestor);

	return ancestor;
}
