#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>


void isPalindromoRec(const char* str, bool* pal, int i) {
	if (i > strlen(str) / 2)
		return;

	if (str[i] != str[strlen(str) - 1 - i]) {
		*pal = false;
	}

	isPalindromoRec(str, pal, i+1);
}



bool IsPalindromo(const char* str) {
	if (str == NULL)
		return false;
	if (strcmp(str, "") == 0)
		return true;

	bool pal = true;
	isPalindromoRec(str, &pal, 0);

	return pal;
}
