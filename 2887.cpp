// #2887 행성터널
https://www.acmicpc.net/problem/2887

#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <queue>
using namespace std;

struct INFO {
	int x, y, z, idx;
};

int N;
int parent[100001];
long long ans;
bool check;
INFO info[100001];

bool compx(const INFO& a, const INFO& b) { return a.x < b.x; }

bool compy(const INFO& a, const INFO& b) { return a.y < b.y; }

bool compz(const INFO& a, const INFO& b) { return a.z < b.z; }

int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	check = false;
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	parent[u] = v;
	check = true;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		parent[i] = i;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &info[i].x, &info[i].y, &info[i].z);
		info[i].idx = i;
	}
	priority_queue<pair<int, pair<int, int>>> pq;

	sort(info, info + N, compx);
	for (int i = 1; i < N; i++)
		pq.push({ -abs(info[i].x - info[i - 1].x), make_pair(info[i].idx, info[i - 1].idx) });

	sort(info, info + N, compy);
	for (int i = 1; i < N; i++)
		pq.push({ -abs(info[i].y - info[i - 1].y), make_pair(info[i].idx, info[i - 1].idx) });

	sort(info, info + N, compz);
	for (int i = 1; i < N; i++)
		pq.push({ -abs(info[i].z - info[i - 1].z), make_pair(info[i].idx, info[i - 1].idx) });

	while (!pq.empty()) {
		int val = -pq.top().first;
		int idx1 = pq.top().second.first;
		int idx2 = pq.top().second.second;
		pq.pop();
		merge(idx1, idx2);
		if (check)
			ans += val;
	}
	printf("%lld\n", ans);
	return 0;
}
