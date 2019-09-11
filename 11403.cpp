// #11403 경로 찾기
https://www.acmicpc.net/problem/11403

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int ans[101][101];
vector <int> vc[101];

void dfs(int s, int e) {
	for (auto there : vc[s]) {
		if (ans[e][there])
			continue;
		ans[e][there] = 1;
		dfs(there, e);
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			scanf("%d", &tmp);
			if(tmp)
				vc[i].push_back(j);
		}
	}
	
	for (int i = 1; i <= N; i++)
		dfs(i, i);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}
