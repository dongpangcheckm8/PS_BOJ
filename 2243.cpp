// #2243 사탕상자
https://www.acmicpc.net/problem/2243

#include <stdio.h>
#define IDX 1048576

int n;
int order[1000001][3];
int ans[1000001];
int tree[IDX * 2];

void input_num(int num, int ea) {
	int idx = num + IDX;
	while (idx) {
		if (ea >= 0) {
			tree[idx] += ea;
		}
		else if (ea < 0) {
			if (tree[idx] + ea >= 0) tree[idx] += ea;
			else tree[idx] = 0;
		}
		idx /= 2;
	}
}

int find_num(int rank) {
	int res = 0;
	int idx = 1;
	int sum = 0;
	while (sum < rank) {
		// if it is leaf node
		if (idx * 2 > IDX + 1000000) {
			if (sum + tree[idx] >= rank) {
				input_num(idx - IDX, -1);
				ans[idx - IDX]--;
				return (idx - IDX);
			}
			else {
				sum += tree[idx];
				idx++;
			}
		}
		else {
			if (sum + tree[idx] < rank) {
				sum += tree[idx];
				idx++;
			}
			else if (sum + tree[idx] > rank) {
				idx *= 2;
			}
			else {
				idx *= 2;
			}
		}
	}
	return res;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &order[i][0], &order[i][1]);
		if (order[i][0] == 2) {
			scanf("%d", &order[i][2]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (order[i][0] == 1) printf("%d\n", find_num(order[i][1]));
		else {
			input_num(order[i][1], order[i][2]);
			if (order[i][2] >= 0) ans[order[i][1]] += order[i][2];
			else {
				if (ans[order[i][1]] + order[i][2] >= 0) ans[order[i][1]] += order[i][2];
				else ans[order[i][1]] = 0;
			}
		}
	}
	return 0;
}
