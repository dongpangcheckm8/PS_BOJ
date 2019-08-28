// #10212 Mystery
https://www.acmicpc.net/problem/10212

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	long long int *temp = (long long int*)malloc(sizeof(long long int));
	printf("%s", ((long long int)temp % 3 ? "Yonsei" : "Korea"));
	return 0;
}
