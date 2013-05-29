/*
ID: silentf1
PROG: milk4
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

bool dp[20001];
int q, p, buk[101], edge, used[101];

void print(int now){
	cout << now;
	for(int  i = 1; i <= now; i++)
		cout << ' ' << buk[used[i]];
	cout << endl;
	exit(0);
}

void judge(int now){
	memset(dp, 0 ,sizeof(dp));
	for(int i = 1; i <= q/buk[used[1]]; i++)
		dp[i*buk[used[1]]] = 1;
	for(int i = 2; i <= now; i++)
		for(int j = buk[used[i]]; j <= q; j++)
			dp[j] |= dp[j - buk[used[i]]];
	if(dp[q]) print(now);
}

void dfs(int lev){
	for(int i = used[lev - 1] + 1; i <= p - (edge - lev); i++){ // ע��ÿ����ο���ѡ��������Ͻ磬���������ι�ѡQ-1�����֣���ô��һ������ֻ����1��2֮��ѡ��ѡ��3����ʹ�ñ����������ʧЧ,��˵�ǰ��ο���ѡ���Ͻ���p-(edge-lev)��
		used[lev] = i;
		if(lev == edge)
			judge(lev);
		else
			dfs(lev + 1);
	}
}

int main(){
	freopen("milk4.in", "r", stdin);
	freopen("milk4.out", "w", stdout);
	cin >> q >> p;
	for(int  i = 1; i <= p; i++) cin >> buk[i];
	sort(buk + 1, buk + 1 + p);

	for(edge = 1; edge <= p; edge++) // DFS-ID
		dfs(1);
	return 0;
}
