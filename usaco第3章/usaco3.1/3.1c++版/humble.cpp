/*
ID: silentf1
PROG: humble
LANG: C++
*/
#include<fstream>
using namespace std;
ifstream fin("humble.in");
ofstream fout("humble.out");
typedef long long int64;
const long long  MAX=2147483647;
int64 num[100001];
long s[101][2],n,ln,k,minx=0;
int main()
{
    fin>>k>>n;
    for(int i=1;i<=k;i++) 
    {
      fin>>s[i][0];
      s[i][1]=0;//��¼��ǰ��ָ�� 
    }
    num[0]=1;
    while(ln<n)
    {
      int64 minx=MAX,temp=0;
      for(long j=1;j<=k;j++)
      {
        if(num[s[j][1]]*s[j][0]>minx) break;//cut 
        for(long p=s[j][1];p<=ln;p++)
        {
          temp=s[j][0]*num[p];
          if(temp>num[ln])
            if(temp<minx) minx=temp;//���� 
              else break;
          else s[j][1]=p;//��¼���λ�� 
        }
      }
      num[++ln]=minx;//�ҵ���ǰ����Сֵ 
    }
    fout<<num[n]<<endl;
    return 0;
}
