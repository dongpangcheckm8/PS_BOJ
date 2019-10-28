// #1181 단어 정렬
https://www.acmicpc.net/problem/1181

#include <stdio.h>
#include <string.h>
using namespace std;

struct st {
	char str[52];
	int len;
	int operator < (const st &ref) {
		if (len < ref.len)
			return 1;
		else if (len == ref.len)
			if (strcmp(str, ref.str) <= 0)
				return 1;
			else
				return 0;
		else
			return 0;
	}
};

int N;
st arr[20001], tmp[20001];

void merge(st* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end)
		tmp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	while(i <= mid)
		tmp[k++] = arr[i++];
	while (j <= end)
		tmp[k++] = arr[j++];
	for (i = start; i <= end; i++)
		arr[i] = tmp[i];
}

void mergeSort(st* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main(void){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i].str);
		arr[i].len = strlen(arr[i].str);
	}
	mergeSort(arr, 0, N - 1);
	printf("%s\n", arr[0].str);
	for (int i = 1; i < N; i++) {
		if (strcmp(arr[i].str, arr[i - 1].str) == 0)
			continue;
		printf("%s\n", arr[i].str);
	}
	return 0;
}
