// #2517 달리기
https://www.acmicpc.net/problem/2517

#include <stdio.h>
#include <algorithm>
#define BUFFER_SIZE 1048576
#define ZERO_IDX 524288
using namespace std;


char getBuffer(void)
{
    static int idx = BUFFER_SIZE;
    static char buffer2[BUFFER_SIZE];
    if(idx == BUFFER_SIZE)
    {
        fread(buffer2, 1, BUFFER_SIZE, stdin);
        idx = 0;
    }
    return buffer2[idx++];
}

int getInt(void)
{
    int num;
    char ch;
    ch = getBuffer();
    while(ch < '0' || '9' < ch)
        ch = getBuffer();
    num = ch - '0';
    ch = getBuffer();
    while('0' <= ch && ch <= '9')
    {
        num = num * 10 + (ch - '0');
        ch = getBuffer();
    }
    return num;
}

struct Man{
	int idx, skill;
	bool operator< (const Man &m){
		return skill < m.skill;
	}
};

int Ans[500000], Tree[10485776];
Man Mans[500000];

void InputNum(int num){
	int idx;
	idx = num + ZERO_IDX;
	while(idx){
		Tree[idx]++;
		idx /= 2;
	}
}

int GetAns(int num){
	int l, r, sum;
	l = ZERO_IDX;
	r = ZERO_IDX + num;
	sum = 0;
	while(l < r){
		if(l%2 == 1){
			sum += Tree[l];
			l++;
		}
		if(r%2 == 0){
			sum += Tree[r];
			r--;
		}
		l /= 2;
		r /= 2;
	}
	if(l == r){
		sum += Tree[r];
	}
	return sum;
}

int main(void){
	int n;
	n = getInt();
	for(int i = 0; i < n ; i++){
		Mans[i].idx = i;
		Mans[i].skill = getInt();
	}	
	sort(Mans, Mans + n);
	for(int i = 0; i < n ; i++){
		Ans[Mans[i].idx] = Mans[i].idx - GetAns(Mans[i].idx) + 1;
		InputNum(Mans[i].idx);
	}
	for(int i = 0; i < n ; i++){
		printf("%d\n", Ans[i]);
	}	
	return 0;	
}
