// #9020 골드바흐의 추측
https://www.acmicpc.net/problem/9020

#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, isPrime[10001];

int main(void){
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;
	int sqrtn = (int)(sqrt(10000));
	for (int i = 2; i <= sqrtn; i++) {
		if (isPrime[i])
			for (int j = i * i; j <= 10000; j += i) {
				isPrime[j] = 0;
			}
	}
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int sum, diff = 10001, a, b;
		scanf("%d", &sum);
		for (int i = 2; i <= sum; i++) {
			if (isPrime[i] && isPrime[sum - i]) {
				if (diff > abs(sum - i - i)) {
					diff = abs(sum - i - i);
					if (sum - i > i) {
						a = i;
						b = sum - i;
					}
					else {
						a = sum - i;
						b = i;
					}
				}
			}
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}
