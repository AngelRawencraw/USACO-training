/*
ID: silentf1
PROG: stall4
LANG: C++
*/
#include <fstream>
#include <cstring>
#define MAXN 1000
#define MAXE 5000
using namespace std;
ofstream fout ("stall4.out",ios::out);
ifstream fin ("stall4.in",ios::in);
struct EDGE{
    int x,y,next;
}edge[MAXE];
int Link[MAXN],head[MAXN],n,m,x,y,tot;
bool use[MAXN];
bool hungary(int node){
    int temp=head[node];
    while(temp){
        if(!use[edge[temp].y]){ //�����δ����
            use[edge[temp].y]=true; //�Ѿ����
            if(!Link[edge[temp].y] || hungary(Link[edge[temp].y])){
                //����ǵ���δƥ��߻����ҵ�����·��������ƥ��
                Link[edge[temp].y]=node; //���õ�ǰƥ���
                return true;
            }
        }
        temp=edge[temp].next;
    }
    return false;
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        fin>>x; //����
        for(int j=1;j<=x;j++){
            fin>>edge[++tot].y;
            edge[tot].x=i; edge[tot].y+=n;
            edge[tot].next=head[i]; head[i]=tot;
        }
    }
    tot=0;
    for(int i=1;i<=n;i++){//hungary
        memset(use,0,sizeof(use));
        if(hungary(i)) tot++;
    }
    fout<<tot<<endl;
	return 0;
}
