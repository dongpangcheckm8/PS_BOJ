// #2751 수 정렬하기 2
https://www.acmicpc.net/problem/2751

#include <stdio.h>

int n;
int tmp[1000001];
int a[1000001];

void merge(int *tmp, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;

	// start와 end가 엇갈리지 않는 동안
	while (i <= mid && j <= end) {
		if (tmp[i] <= tmp[j]) {
			a[k] = tmp[i];
			i++;
		}
		else {
			a[k] = tmp[j];
			j++;
		}
		k++;
	}
	// 뒤쪽 배열이 남아있다면
	if (i > mid) {
		for (int t = j; t <= end; t++) {
			a[k] = tmp[t];
			k++;
		}
	}
	// 앞쪽 배열이 남아있다면
	else {
		for (int t = i; t <= mid; t++) {
			a[k] = tmp[t];
			k++;
		}
	}

	// 정렬된 배열을 삽입
	for (int t = start; t <= end; t++) {
		tmp[t] = a[t];
	}
}

void merge_sort(int *tmp, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(tmp, start, mid);
		merge_sort(tmp, mid + 1, end);
		merge(tmp, start, mid, end);
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &tmp[i]);
	merge_sort(tmp, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d\n", tmp[i]);
	return 0;
}


