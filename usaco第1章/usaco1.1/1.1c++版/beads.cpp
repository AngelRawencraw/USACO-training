/*
ID: silentf1
PROG: beads
LANG: C++
*/
#include <fstream>
#include <cstring>
using namespace std;
ofstream fout ("beads.out",ios::out);
ifstream fin ("beads.in",ios::in);
int num,maxn=-1;
char beads[1000];
void work()
{
	for(int i=0;i<num*2;i++)//�±��0��ʼ
	{
		char l=beads[i],r=beads[i+1];//ö��������չ�˵�,һ������,һ������
		int nl=0,nr=0,lj=0;//��ǰ��չ����,lj��ֹ��չ����
		for(int j=i;j>=0;j--)
			if ((beads[j]==l||beads[j]=='w')&&lj<num)
			{
				if (j-1>=0) if (l=='w') l=beads[j-1];//important,�ͽ�ɨ�跨��(����),������˭,���žͲ���˭.
				++nl;
				++lj;//����
			}
				else break;
		for(int j=i+1;j<num*2;j++)
			if ((beads[j]==r||beads[j]=='w')&&lj<num) 
			{
				if (j+1<num*2) if (r=='w') r=beads[j+1];//important
				++nr;
				++lj;
			}
				else break;
		if (nr+nl>maxn) maxn=nl+nr;//����
	}
	fout<<maxn<<endl;
}
void init()
{
	fin>>num;
	char beads2[1000];
	fin>>beads2;
	strcpy(beads,beads2);//��bead2��ֵ��bead.	
	strcat(beads,beads2);//ʹ����ɻ�״
}
int main()
{
	init();
	work();
	return 0;
}
