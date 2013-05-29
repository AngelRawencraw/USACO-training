/*
ID: silentf1
PROG: crypt1
LANG: C++
*/
#include <fstream>
using namespace std;
ofstream fout ("crypt1.out",ios::out);
ifstream fin ("crypt1.in",ios::in);
int n,num[10],a[4],b[3],di[5]={0,1000,100,10,1};
bool isin(int temp)
{
	for(int i=1;i<=n;i++)
		if (temp==num[i]) return true;
	return false;
}
int compute()
{
	int tea=a[1]+a[2]*10+a[3]*100,c=tea*b[1],d=tea*b[2],e=d*10+c;//��������
	if ((c>999)||(d>999)) return 0;//��֦
	if (e>9999) return 0;//��֦
	for(int i=2;i<=4;i++)//�����ж�
	{
		if (!isin(c/di[i])) return 0;
		if (!isin(d/di[i])) return 0;
		c=c%di[i];
		d=d%di[i];
	}
	for(int j=1;j<=4;j++)//�����ж�
	{
		if (!isin(e/di[j])) return 0;
		e=e%di[j];
	}
	return 1;
}
int main()
{
	fin>>n;
	for(int i=1;i<=n;i++)
		fin>>num[i];
	int maxn=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)//������ö����λ���ĸ�����λ
			{
				a[1]=(a[2]=num[j],a[3]=num[i],num[k]);
				for(int p=1;p<=n;p++)
					for(int q=1;q<=n;q++)//ö����λ���ĸ�����λ
					{
						b[1]=num[q];b[2]=num[p];
						maxn+=compute();//����
					}
			}
	fout<<maxn<<endl;
    return 0;
}
