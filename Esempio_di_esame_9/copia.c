#define _CRT_SECURE_NO_WARNINGS

#include"list.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

Item* CopiaDaN(const Item* i, int n) {
	if (ListIsEmpty(i) || i == NULL)
		return NULL;

	Item* l = i;
	Item* copy = ListCreateEmpty();

	int c = 1;
	while (true) {

		if (c >= n) {
			copy = ListInsertBack(copy, &l->value);
		}

		if (l->next == NULL)
			break;

		l = l->next;
		c++;
	}

	if (c < n)
		return NULL;

	return copy;
}


/*
int main(void) {
	Item* list = malloc(sizeof(Item));
	list->value = 40;

	list->next = malloc(sizeof(Item));
	list->next->value = 20;

	list->next->next = malloc(sizeof(Item));
	list->next->next->value = 10;

	list->next->next->next = NULL;

	int n = 4;

	Item* copia = CopiaDaN(list, n);

	return 0;
}
*/