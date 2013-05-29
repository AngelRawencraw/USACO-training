/*
ID: silentf1
PROG: contact
LANG: C++
*/
#include <fstream>
#define iszero(x) (x=='0'?0:1)
using namespace std;
ofstream fout ("contact.out",ios::out);
ifstream fin ("contact.in",ios::in);
long a,b,n,len,head=1,bin[4096][13],val[51];
char chuli[14],temp;
inline void queuein(char dan,long pos)
{
    if(pos%b==0) chuli[b]=dan;
    else chuli[pos%b]=dan;
}
inline char queueout(long pos)
{
    if(pos%b==0) return chuli[b];
    else return chuli[pos%b];
}
inline void change(const char chuli[],const int &len)
{
    int num=0,i=1,tlen=len;
    while(tlen!=0)
    {
        num+=iszero(chuli[i])<<(i-1);
        tlen--;
        i++;
    }
    bin[num][len]++;
}
int main()
{
    fin>>a>>b>>n;
    char dr[14];
    int k,hh,first=a;
    while(temp=fin.get())
    {
        if(temp=='1' || temp=='0')
		{
			len++;
			queuein(temp,len);
			if(len-head>=b) {head++;first=a;}//��չͷָ��
			while(len-head+1>=first)
			{
				for(k=1;k<=first;k++)//��ȡ�ַ���
					dr[first-k+1]=queueout(head+k-1);
				change(dr,first);//���
				first++;//��չ����
			}
		}
		else if(fin.eof())//������ĩ��λ
			{
				for(int i=head+1;i<=len;i++)
				{
					first=a;
					while(len-i+1>=first)
					{
						for(k=1;k<=first;k++)//��ȡ�ַ���
							dr[first-k+1]=queueout(i+k-1);//important
						change(dr,first);//���
						first++;
					}
				}
				break;
			}
	}
    for(int i=0;i<=4095;i++)//��ȡ����ǰN������
      for(int j=a;j<=b;j++)
      if(bin[i][j]!=0)
        {
            k=1;
            while(bin[i][j]<val[k]) k++;
            if(bin[i][j]!=val[k])
            {
                for(int i1=n;i1>=k+1;i1--) val[i1]=val[i1-1];
                val[k]=bin[i][j];
            }
        }
    for(int i=1;i<=n;i++)
    if(val[i]!=0)
    {
        hh=0;
		fout<<val[i]<<endl;
        for(int q=a;q<=b;q++)//���������
            for(int p=0;p<=4095;p++)
            if(bin[p][q]==val[i])
            {
                hh++;
                if(hh%6!=1) fout<<' ';
                for(int k=q;k>=1;k--)
                    if((p>>(k-1))&1) fout<<'1'; else fout<<'0';
                if(hh%6==0) fout<<endl;
            }
        if(hh%6!=0) fout<<endl;
    }
    return 0;
}
