#define _CRT_SECURE_NO_WARNINGS

#include"list.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

Item* CreaDaMinori(const Item* i, int v) {
	if (ListIsEmpty(i))
		return NULL;

	Item* newList = ListCreateEmpty();
	Item* l = i;
	
	while (true) {

		if (l->value <= v)
			newList = ListInsertBack(newList, &(l->value));
		if (l->next == NULL)
			break;
		l = l->next;
	}

	return newList;
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

	Item* minori = CreaDaMinori(list, 20);

	return 0;
}
*/