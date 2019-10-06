// #17435 합성함수와 쿼리
https://www.acmicpc.net/problem/17435

#include <stdio.h>
#define MAX 500001
#define MAX_D 19

int M, Q, arr[MAX][MAX_D];

int main(void) {
	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
		scanf("%d", &arr[i][0]);
	for (int j = 1; j < MAX_D; j++) {
		for (int i = 1; i <= M; i++) {
			arr[i][j] = arr[arr[i][j - 1]][j - 1];
		}
	}
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int n, x;
		scanf("%d %d", &n, &x);
		for (int j = MAX_D - 1; j >= 0; j--) {
			if (n >= 1 << j) {
				n -= 1 << j;
				x = arr[x][j];
			}
		}
		printf("%d\n", x);
	}
	return 0;
}
