// #11652 카드
https://www.acmicpc.net/problem/11652

#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
long long arr[1000001];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);

	long long ans = arr[0];
	int ans_cnt = 1;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1]) cnt++;
		else cnt = 1;
		if (ans_cnt < cnt) {
			ans_cnt = cnt;
			ans = arr[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
