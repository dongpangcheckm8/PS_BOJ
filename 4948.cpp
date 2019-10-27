// #4948 베르트랑 공준
https://www.acmicpc.net/problem/4948

#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

int N, isPrime[250001];

int main(void){
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;
	int sqrtn = (int)(sqrt(250000));
	for (int i = 2; i <= sqrtn; i++) {
		if (isPrime[i])
			for (int j = i * i; j <= 250000; j += i) {
				isPrime[j] = 0;
			}
	}
	while (1) {
		scanf("%d", &N);
		if (!N)
			break;
		int cnt = 0;
		for (int i = N + 1; i <= N * 2; i++) {
			if (isPrime[i])
				cnt++;
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}
