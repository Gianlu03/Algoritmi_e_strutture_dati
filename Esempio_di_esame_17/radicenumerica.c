#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<ctype.h>
#include<math.h>

int radiceNumericaRec(int n) {
	if (n < 10)
		return n;

	return n % 10 + radiceNumericaRec(n / 10);
}

int main(int argc, char** argv) {
	if (argc != 2)
		return 1;

	int n = atoi(argv[1]);

	if (n < 0) return 1;

	int sum = n;
	
	while(sum >= 10)
		sum = radiceNumericaRec(sum);

	printf("%d", sum);

	return 0;
}