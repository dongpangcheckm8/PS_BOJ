// #11562 백양로 브레이크
https://www.acmicpc.net/problem/11562

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#define INF 987654321
using namespace std;

int N, M, U, V, B, K, S, E;
int arr[251][251], dist[251][251], root[251][251];

void fw(void) {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if(i != j)
				dist[i][j] = INF;
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &U, &V, &B);
		dist[U][V] = 0;
		if (!B)
			dist[V][U] = 1;
		else
			dist[V][U] = 0;
	}
	scanf("%d", &K);
	fw();
	for (int i = 1; i <= K; i++) {
		scanf("%d %d", &S, &E);
		printf("%d\n", dist[S][E]);
	}
	return 0;
}
