// #11437 LCA
https://www.acmicpc.net/problem/11437

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 17;
int N, M;
int depth[50001], parent[50001][MAX];
vector <int> vc[50001];

void make(int curr) {
	for (auto there : vc[curr]) {
		if (depth[there] == -1) {
			parent[there][0] = curr;
			depth[there] = depth[curr] + 1;
			make(there);
		}
	}
}

int main(void) {
	scanf("%d", &N);
	memset(depth, -1, sizeof(depth));
	memset(parent, -1, sizeof(parent));
	for (int i = 1; i < N; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		vc[from].push_back(to);
		vc[to].push_back(from);
	}
	depth[1] = 1;
	make(1);
	for (int j = 0; j < MAX - 1; j++) {
		for (int i = 1; i <= N; i++) {
			if (parent[i][j] != -1) {
				parent[i][j + 1] = parent[parent[i][j]][j];
			}
		}
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		int u = from, v = to;
		if (depth[u] < depth[v])
			swap(u, v);
		int diff = depth[u] - depth[v];
		for (int j = 0; diff; j++) {
			if (diff % 2)
				u = parent[u][j];
			diff /= 2;
		}
		if (u != v) {
			for (int j = MAX - 1; j >= 0; j--) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}
		printf("%d\n", u);
	}
	return 0;
}
