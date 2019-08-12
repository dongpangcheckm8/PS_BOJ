// #2331 
https://www.acmicpc.net/problem/2331

#include <stdio.h>
#include <cmath>
using namespace std;
#define MAX 1000000

int A, P;
int arr[MAX], dp[MAX];

int get_sol(int num, int p) {
	int ret = 0;
	while (num) {
		ret += pow(num % 10, p);
		num /= 10;
	}
	return ret;
}

int main(void) {
	scanf("%d %d", &A, &P);
	arr[1] = A;
	dp[A]++;
	int idx = 1;
	int target;
	while (true) {
		arr[idx + 1] = get_sol(arr[idx], P);
		dp[arr[idx + 1]]++;
		if (dp[arr[idx + 1]] >= 2) {
			target = arr[idx + 1];
			break;
		}
		idx++;
	}
	int i;
	for (i = 1; i <= idx + 1; i++) {
		if (arr[i] == target)
			break;
	}
	printf("%d\n", i - 1);
	return 0;
}
