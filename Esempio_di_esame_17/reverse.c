#define _CRT_SECURE_NO_WARNINGS

#include"list.h"

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<ctype.h>
#include<math.h>

Item* Reverse(Item* i) {
	if (ListIsEmpty(i) || i == NULL)
		return ListCreateEmpty();


	Item* tmp = i; //temp tiene il primo
	Item* copy = i;
	Item* copy2 = i;

	size_t len = 0;

	while (copy->next != NULL) {
		copy = copy->next;
		len++;
	}
	
	i = copy;
	Item* runI = i;

	//fino qui ok

	for (int j = 1; j <= len; j++) {
		copy = copy2;
		for (int k = 0; k < len - j; k++) {
			copy = copy->next;
		}
		runI->next = copy;
		runI = runI->next;
	}
	runI->next = NULL;
	

	return i;

}
