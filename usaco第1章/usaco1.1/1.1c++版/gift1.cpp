/*
ID: silentf1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct leixing
{
	char name[15];//���� 
	int own,out;//�ֱ��ʾӵ�к�֧�� 
};
ofstream fout ("gift1.out",ios::out);
ifstream fin ("gift1.in",ios::in);
int np;
leixing abc[11];
void work()
{
	char name1[15],name2[15];
	int a,b;
	while (fin>>name2)
	{
		fin>>a>>b;//������ʼ��Ǯ�Լ�Ҫ�ֵ����� 
		if (b!=0) 
		{
			for(int i=1;i<=b;i++)
			{
				fin>>name1;//�ֱ��������
				for(int j=1;j<=np;j++)//ö�ٱȽ�˭��õ�Ǯ 
					if (strcmp(name1,abc[j].name)==0) abc[j].own=abc[j].own+a/b;
			}
			for(int j=1;j<=np;j++)
				if (strcmp(name2,abc[j].name)==0)//ö������֧�� 
				{
					int c=a/b;
					abc[j].out=a+abc[j].out;
					abc[j].own=a-c*b+abc[j].own;//���²��ɷֵ�Ǯ 
				}
		}
	}
	for (int i=1;i<=np;i++)
		fout<<abc[i].name<<' '<<abc[i].own-abc[i].out<<endl;//output
}
int main()
{
	fin>>np;
	for(int i=1;i<=np;i++)
		fin>>abc[i].name;//�������� 
	work();
	return 0;
}
