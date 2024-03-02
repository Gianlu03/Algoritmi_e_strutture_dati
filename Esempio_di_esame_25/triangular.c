#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<stdint.h>

int nTriangularRec(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 3;

	return 3 * nTriangularRec(n - 1) - 3 * nTriangularRec(n - 2) + nTriangularRec(n - 3);
}

int main(int argc, char** argv) {
	if (argc != 2)
		return 1;

	int n = atoi(argv[1]);

	if (n < 0) return 1;

	int t = nTriangularRec(n);

	printf("%d", t);

	return 0;


}