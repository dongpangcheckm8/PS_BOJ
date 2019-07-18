// #11003 최솟값 찾기
https://www.acmicpc.net/problem/11003

#include <stdio.h>
#include <deque>
using namespace std;

int n, L;
int arr[5000001];

void printMin(int arr[], int n, int L) {
	deque <int> deq;
	// first step
	int i;
	for (i = 1; i <= L; i++) {
		while ((!deq.empty()) && arr[i] < arr[deq.back()]) {
			deq.pop_back();
		}
		deq.push_back(i);
		printf("%d ", arr[deq.front()]);
	}
	// rest steps
	for (; i <= n; i++) {
		while ((!deq.empty()) && deq.front() <= i - L) {
			deq.pop_front();
		}
		while ((!deq.empty()) && arr[i] <= arr[deq.back()]) {
			deq.pop_back();
		}
		deq.push_back(i);
		printf("%d ", arr[deq.front()]);
	}
}

int main(void) {
	scanf("%d %d", &n, &L);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	printMin(arr, n, L);
	return 0;
}
