// #2162 선분 그룹
https://www.acmicpc.net/problem/2162


#include <stdio.h>
#include <algorithm>
using namespace std;

typedef pair <int, int> pi;

pi p[6002];
int parent[3001], cnt[3001];
int N;

int _find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = _find(parent[x]);
}

void _union(int x, int y) {
	x = _find(x);
	y = _find(y);
	if (x > y)
		swap(x, y);
	parent[x] = y;
	cnt[y] += cnt[x];
}

int ccw(pi a, pi b, pi c) {
	int tmp = a.first * b.second + b.first * c.second + c.first * a.second;
	tmp -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (tmp > 0)
		return 1;
	if (tmp < 0)
		return -1;
	return 0;
}

int is_cross(pi a, pi b, pi c, pi d) {
	int r1 = ccw(a, b, c) * ccw(a, b, d);
	int r2 = ccw(c, d, a) * ccw(c, d, b);
	if (!r1 && !r2) {
		if (a > b) 
			swap(a, b);
		if (c > d) 
			swap(c, d);
		return c <= b && a <= d;
	}
	return r1 <= 0 && r2 <= 0;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N * 2; i++) {
		scanf("%d %d", &p[i].first, &p[i].second);
		parent[i / 2] = i / 2;
		cnt[i / 2] = 1;
	}
	int ans1 = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (is_cross(p[i * 2 - 1], p[i * 2], p[j * 2 - 1], p[j * 2])) {
				int x = _find(i);
				int y = _find(j);
				if (x != y) {
					_union(x, y);
					ans1++;
				}
			}
		}
	}
	int ans2 = 0;
	for (int i = 1; i <= N; i++) {
		ans2 = max(ans2, cnt[i]);
	}
	printf("%d\n%d\n", N - ans1, ans2);
	return 0;
}
