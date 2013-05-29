/*
ID: silentf1
PROG: fence
LANG: C++
*/
#include <fstream>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
ofstream fout ("fence.out",ios::out);
ifstream fin ("fence.in",ios::in);
int n,x,y,point[2001],node[501],lenp=0,Max,init=1,edge[501][501];
inline int Del(int pos){ //ѡ����С�ĵ�
    int Min=9999;
    for(int i=1;i<=Max;i++) //�쿴��ͨ��
        if(edge[i][pos]) Min=MIN(Min,i);
    return Min;
}
void eulerian(int pos){
    int delnode;
    if(node[pos]==0) point[++lenp]=pos; //�Ѿ�������ϼ������
    else{
        while(node[pos]!=0){ //delete
            delnode=Del(pos);
            node[delnode]--;
            node[pos]--;
            edge[pos][delnode]=--edge[delnode][pos];
            eulerian(delnode);
        }
        point[++lenp]=pos;//������Ҫ���
    }
}
int main()
{
    fin>>n;
    for(int i=1;i<=500;i++)
        for(int j=1;j<=500;j++)
            edge[i][j]=0;
    for(int i=1;i<=n;i++){
        fin>>x>>y;
        Max=MAX(MAX(Max,x),y);
        edge[x][y]=++edge[y][x];
        ++node[x];
        ++node[y];
    }
    for(int i=1;i<=Max;i++) if(node[i]&1) {init=i;break;}//����ʼ��
    eulerian(init);
    for(int i=lenp;i>=1;i--) fout<<point[i]<<endl;//�������
    return 0;
}
