// #11438 LCA2
https://www.acmicpc.net/problem/11438

#include <stdio.h>
#include <vector>
#include <cmath>

#define swap(a, b){int t = a; a = b; b = t;}
#define MAX_SIZE 100001

using namespace std;

int depth[MAX_SIZE];
int ac[MAX_SIZE][20];

vector <int> vc[MAX_SIZE];
int n, m, max_level;

void get_tree(int here, int parent){
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;
	max_level = (int)floor(log2(MAX_SIZE));
	for(int i = 1; i <= max_level; i++){
		int tmp = ac[here][i - 1];
		ac[here][i] = ac[tmp][i - 1];
	}
	int len = vc[here].size();
	for(int i = 0; i < len; i++){
		int there = vc[here][i];
		if(there != parent){
			get_tree(there, here);
		}
	}
}

int main(void){
	scanf("%d", &n);
	int from, to;
	for(int i = 1;  i < n; i++){
		scanf("%d %d", &from, &to);
		vc[from].push_back(to);
		vc[to].push_back(from);
	}
	depth[0] = -1;
	get_tree(1, 0);
	scanf("%d", &m);
	while(m--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(depth[a] != depth[b]){
			if(depth[a] > depth[b])
				swap(a, b);
			for(int i = max_level; i >= 0; i--){
				if(depth[a] <= depth[ac[b][i]])
					b = ac[b][i];
			}
		}
		int lca = a;
		if(a != b){
			for(int i = max_level; i >= 0; i--){
				if(ac[a][i] != ac[b][i]){
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}
		printf("%d\n", lca);
	}
	return 0;
}
