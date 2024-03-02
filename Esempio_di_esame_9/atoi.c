#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<math.h>


//da 0 a 9 in ascii : da 48 a 57

void atoiRec(char* str, int len, int* n, int i) {
	if (str[i] == 0)
		return;

	*n += ((int)str[i] - 48)*pow(10, len-1);

	atoiRec(str, len - 1, n, i + 1);

}

int AToI(const char* str) {
	if (str == NULL)
		return 0;

	int n = 0;
	atoiRec(str, strlen(str), &n, 0);

	return n;
}

/*
int main(void) {

	char* str = "19832";

	int n = AToI(str);
	printf("%d", n);
	return 0;
}
*/