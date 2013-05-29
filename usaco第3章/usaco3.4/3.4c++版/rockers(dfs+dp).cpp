/*
ID: silentf1
PROG: rockers
LANG: C++
*/
#include <fstream>
#define MAX(a,b) ((a)>(b)?(a):(b))//ֻ��3����
using namespace std;
ofstream fout ("rockers.out",ios::out);
ifstream fin ("rockers.in",ios::in);
long dp[21][21][21],v[21],n,t,m,Max=0;
void dfsdp(int lev,int pos,long value){//���μ���ÿ������,ʹ��dfs�ᳬʱ
    if(lev>m){
        Max=MAX(Max,value);
        return;
    }
    if(pos>=n) dfsdp(lev+1,n,value);
    else{
        long dp[21][21];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=t;j++) dp[i][j]=0;
        for(int i=pos+1;i<=n;i++)
            for(int j=1;j<=t;j++){
                if(j-v[i]>=0) dp[i][j]=MAX(dp[i-1][j],dp[i-1][j-v[i]]+1);
                else dp[i][j]=dp[i-1][j];
                dfsdp(lev+1,i,value+dp[i][j]);
            }
    }
}
int main()
{
    fin>>n>>t>>m;
    for(int i=1;i<=n;i++) fin>>v[i];
    dfsdp(1,0,0);
    fout<<Max<<endl;
    return 0;
}
