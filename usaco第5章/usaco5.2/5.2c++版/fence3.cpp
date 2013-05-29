/*
ID: silentf1
PROG: fence3
LANG: C++
*/
#include <iostream> //ģ���˻��㷨,�����ƽ�
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip> // ��ʾС����

#define MAX(a, b) (a > b? a : b)
#define MIN(a, b) (a < b? a : b)
#define prec 0.0000001
#define INF 0x7FFFFFFF

using namespace std;

struct fence{
	int x1, y1, x2, y2;
}Node[151], map;
int F, step[] = {0, 50, 10, 1}, s = 3;
double x, y, l; //step�ǳ�ʼ����

inline void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

inline double dist(int x1, int y1, int x2, int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double totdist(const double &x, const double &y){
	double tot  = 0;
	for(int i = 1; i <= F; i++){
		if(Node[i].y1 == Node[i].y2){ // ƽ����x
			if(x >= Node[i].x1 && x <= Node[i].x2) // ����������
				tot += fabs(y - Node[i].y1);
			else if(x > Node[i].x2)
				tot += dist(x, y, Node[i].x2, Node[i].y2);
			else
				tot += dist(x, y, Node[i].x1, Node[i].y1);
		}else{	// ��yƽ��
			if(y >= Node[i].y1 && y <= Node[i].y2) // ����������
				tot += fabs(x - Node[i].x1);
			else if(y > Node[i].y2)
				tot += dist(x, y, Node[i].x2, Node[i].y2);
			else
				tot += dist(x, y, Node[i].x1, Node[i].y1);
		}
	}
	return 	tot;
}

inline void anneal(fence map, int now){
	for(int i = map.x1 - step[now - 1]; i <= map.x2 + step[now - 1]; i += step[now]){
		for(int j = map.y1 - step[now - 1]; j <= map.y2 + step[now - 1]; j += step[now]){
			double count = totdist(i, j);
			if (l > count){
				l = count;
				x = i;
				y = j;
			}
		}
	}
}

void search(){
	for(int now = 1; now <= s; now++){
		anneal(map, now); //�������һ�κ󣬵�ͼ�ı߽�Ͳ���Ҫ�ˣ���Ϊ��ʱ�Ѿ���һ�����ŵ��ˣ��������Ϊ���ļ�������
		if(x != 0 && y != 0){  //ע��Ҫ���¹���ſ����滻
			map.x1 = map.x2 = x;
			map.y1 = map.y2 = y;
		}
	}
}

int main(){
	freopen("fence3.in", "r", stdin);
	freopen("fence3.out", "w", stdout);
	map.x1 = map.y1 = l = INF;
	x = y = 0.0;
	
	cin >> F;
	for(int i = 1; i <= F; i++){
		cin >> Node[i].x1 >> Node[i].y1 >> Node[i].x2 >> Node[i].y2;	
		Node[i].x1 *= 10, Node[i].y1 *= 10, Node[i].x2 *= 10, Node[i].y2 *= 10;
		if(Node[i].x1 > Node[i].x2) swap(Node[i].x1, Node[i].x2);
		if(Node[i].y1 > Node[i].y2) swap(Node[i].y1, Node[i].y2);	//��Ϊ����ƽ�������������������Ľ���û��Bug
		map.x1 = MIN(Node[i].x1, map.x1);
		map.y1 = MIN(Node[i].y1, map.y1);
		map.x2 = MAX(Node[i].x2, map.x2);
		map.y2 = MAX(Node[i].y2, map.y2);		//��õ�ͼ�߽�
	}
	
	search();

	cout.precision(1);
	cout.setf(ios::fixed);
	cout << x/10.0 << ' ' << y/10.0 << ' ' << l/10.0 << endl;
	return 0;
}
