// #5568 카드 놓기
https://www.acmicpc.net/problem/5568

#include <stdio.h>
#define MAX_SIZE 100000001

int arr[11], cnts[11], visit[11];
bool check[MAX_SIZE];
int n, k;

int make_num(int cnt, int res) {
	int ret = 0;
	if (cnt == k) {
		if (!check[res]) {
			check[res] = true;
			return 1;
		}
		else return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			if (cnts[i] == 1) {
				ret += make_num(cnt + 1, res * 10 + arr[i]);
			}
			else {
				ret += make_num(cnt + 1, res * 100 + arr[i]);
			}
			visit[i] = 0;
		}
	}
	return ret;
}

int main(void) {
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] >= 10) cnts[i] = 2;
		else cnts[i] = 1;
	}
	printf("%d\n", make_num(0, 0));
	return 0;
}
