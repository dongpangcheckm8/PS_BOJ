// #7578 공장
https://www.acmicpc.net/problem/7578

#include <stdio.h>
#define ZERO_IDX (1 << 20)
#define MAX_SZ 500001
typedef long long ll;

int A[MAX_SZ], B[MAX_SZ * 2];
ll tree[ZERO_IDX * 2];
int N;

void update(int i, int val) {
	int idx = i + ZERO_IDX;
	while (idx) {
		tree[idx] += val;
		idx >>= 1;
	}
}

ll sum(int i, int j) {
	ll res = 0;
	int l = ZERO_IDX + i;
	int r = ZERO_IDX + j;
	while (l < r) {
		if (l % 2)
			res += tree[l++];
		if (!(r % 2))
			res += tree[r--];
		l >>= 1;
		r >>= 1;
	}
	if (l == r)
		res += tree[l];
	return res;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= N; i++) {
		int idx;
		scanf("%d", &idx);
		B[idx] = i;
	}
	ll res = 0;
	for (int i = 1; i <= N; i++) {
		int A_val = A[i];
		int B_idx = B[A_val];
		res += sum(B_idx + 1, N);
		update(B_idx, 1);
	}
	printf("%lld\n", res);
	return 0;
}
