/*
ID: silentf1
PROG: calfflac
LANG: C++
*/
#include<cstring>
#include<cctype>
#include<fstream>
using namespace std;
ofstream fout ("calfflac.out",ios::out);
ifstream fin ("calfflac.in",ios::in);
char a;
string s="";
int maxn=-1,front=-1,last=-1,len=0,i=0,x,y,z=0;
bool istrue(char a,char b)//�жϺ���
{
	if(a==b) return true;
	if(a+32==b) return true;
	if(a-32==b) return true;
	return false;
}
void work()
{
	while((x>=0)&&(y<len))//δ����
		{
			if (istrue(s[x],s[y])) {if (z>maxn) {maxn=z;front=x;last=y;}
				  if((x-1>=0)&&(y+1)<len) {x--;y++;z+=2;} else break;}
			else break;//�ۼ�
			//����������ĸ������.
			while(!isalpha(s[x])&&(x>0)) {x--;}
			while(!isalpha(s[y])&&(y+1<len)) {y++;}
		}
}
int main()
{
   	 while (!fin.eof())
	{
         a=fin.get();
         if (!fin.eof()) {s+=a;len++;}
	}//��ʼ��
	len--;
        while (i<len)
	{
		while(!isalpha(s[i])&&(i+1<len)) {i++;}//init;����������ĸ���ַ�(��ͬ)
		x=i;y=i;z=1;//odd,zΪ��λ��չ����
		work();
		x=i;y=i+1;z=2;//even
		while(!isalpha(s[y])&&(y+1<len)) {y++;}//init;
		if (istrue(s[x],s[y])) work();//������֤ͬ������չ�ı�Ҫ
		i++;//����ָ��
	}
	fout<<maxn<<endl;
	for(int j=front;j<=last;j++)
		fout<<s[j];
	fout<<endl;
    return 0;
}
