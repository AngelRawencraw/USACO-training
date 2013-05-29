/*
ID: silentf1
PROG: ariprog
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("ariprog.out",ios::out);
ifstream fin ("ariprog.in",ios::in);
int n,m,sq[125000],a[20000],b[20000];
bool squ[125000]={false};//�����ж��Ƿ�����������
void qsort(int l,int r)
{
	int i,j,x,y;
	i=l;
	j=r;
	x=sq[(i+j)/2];
	do
	{
		while(sq[i]<x) i++;
		while(sq[j]>x) j--;
		if(i<=j)
		{
			y=sq[i];
			sq[i]=sq[j];
			sq[j]=y;
			i++;
			j--;
		}
	}
	while(i<=j);
	if (i<r) qsort(i,r);
	if (l<j) qsort(l,j);
}
void work()
{
	//create
	int temp=-1,zt;
	for(int i=0;i<=m;i++)//����˫ƽ������
		for(int j=0;j<=m;j++)
		{
			zt=i*i+j*j;//compute
			if (!squ[zt]) {temp++;sq[temp]=zt;}
			squ[zt]=true;
		}
	qsort(0,temp);//����
	int max=2*m*m,gcmax=0,pointer=0;//maxΪ������ƽ������
	bool son=false;
	//main
	for(int i=0;i<=(temp-n+1);i++)//ͷָ��
	{
		gcmax=(max-sq[i])/(n-1);//���Ŀ��ܹ���
		for(int j=1;j<=gcmax;j++)//ö���ж�
		{
			bool flag=true;
			for(int k=1;k<n;k++)
				if(!squ[sq[i]+k*j]) 
				{
					flag=false;
					break;
				}
			if(flag) 
			{
				son=true;//�п�������
				pointer++;
				a[pointer]=sq[i];
				b[pointer]=j;
			}
		}
	}
	int x=0;
	if(son)//ʹ����ĭ����b,�Ƚ��ȶ�,�������a;
	{
		for(int i=1;i<=pointer-1;i++)
			for(int j=1;j<=pointer-i;j++)
				if (b[j]>b[j+1])
				{
					x=a[j];a[j]=a[j+1];a[j+1]=x;
					x=b[j];b[j]=b[j+1];b[j+1]=x;
				}
		for(int i=1;i<=pointer;i++)
			fout<<a[i]<<' '<<b[i]<<endl;
	}
	if(!son) fout<<"NONE"<<endl;
}
int main()
{
	fin>>n>>m;
	work();
    return 0;
}
