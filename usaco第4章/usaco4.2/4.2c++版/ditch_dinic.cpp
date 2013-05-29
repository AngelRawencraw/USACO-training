/*
ID: silentf1
PROG: ditch
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<climits>
typedef long long INT64;
const INT64 MAXN = 205; //���ڵ���Ŀ
struct edge{  //ʹ�ñ߱�洢
    int x,y,cap; //�ߵ����߷ֱ���x,y;������cap;��Ϊ������Ϊ�����������Խ�������;
    edge *next,*target; //��xΪ��ͷ���ڽӱߺͷ����;
    edge(){} //ȱʡ���캯��
    edge(int x,int y,int c,edge *n):x(x),y(y),cap(c),next(n),target(0){} //�Զ��幹�캯��
    void * operator new (size_t,void *ptr){return ptr;} //����new�����
}*EDGE[MAXN];
INT64 MAXTOTAL;  //��¼�����
long N,M,x,y,cap,Source,Sink,Queue[10*MAXN],Dist[MAXN]; //DistΪ�ֲ�ͼ���
edge *path[MAXN],*Stack[MAXN]; //�ֱ��¼����·�ͻ�����ջ
bool RefreshDistLabel(){ //�ֲ�ͼ���캯����ͬʱѰ������·
    int head=0,tail=0,now;
    memset(Dist,-1,sizeof(Dist));
    Dist[Source]=0; //Դ���ξ���
    Queue[++tail]=Source;
    while(head<tail){
        now=Queue[++head];
        for(edge *e=EDGE[now];e;e=e->next){ //�鿴�����ڽ�
            if(e->cap==0) continue; //�Ѿ��ޱ�������
            if(Dist[e->y]==-1){ //δ��չ
                Dist[e->y]=Dist[e->x]+1; //���ϸ������չ.(e->x����nowҲ����)
                Queue[++tail]=e->y;
                if(e->y==Sink) return 1; //�ҵ��Ϸ�������˳�
            }
        }
    }
    return 0;
}
void FindMaxFlow(){
    int Lpath=1,top=Source,record,delta;
    memcpy(Stack,EDGE,sizeof(EDGE));
    while(top>0){
        if(top==Sink){ //�ҵ�����·
            delta=INT_MAX;
            for(int i=1;i<Lpath;i++) //�ҵ���������С����
                if(delta>path[i]->cap){
                    delta=path[i]->cap;
                    record=i; //��¼�����ļ̳г�����
                }
            for(int i=1;i<Lpath;i++){ //����
                path[i]->cap-=delta;
                path[i]->target->cap+=delta;
            }
            Lpath=record; //����
            top=path[Lpath]->x; //����
            MAXTOTAL+=delta; //���������
        }
        edge *temE;
        for(temE=Stack[top];temE;temE=temE->next){ //�鿴�����ڽ�
            if(temE->cap==0) continue; //���Ϸ�
            if(Dist[top]+1==Dist[temE->y]) break; //�Ϸ�
        }
        Stack[top]=temE; //��¼��ǰ��DFSλ��
        if(temE){ //�ҵ��������
            path[Lpath++]=temE; //���
            top=temE->y; //�����������
        }
        else{ //�Ѿ��޷�����
            Dist[top]=-1; //ɾ����ǰ��
            if(Lpath==1) return; //����޷��������˳�.(topҲ����)
            top=path[--Lpath]->x; //����
        }
    }
}
int main(){
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    scanf("%d%d",&M,&N);
    Source=1;
    Sink=N;
    edge *tempedge=new edge[2*M]; //��ʱ�����߱�
    while(M--){
        scanf("%d%d%d",&x,&y,&cap);
        EDGE[x]=new((void *)tempedge++) edge(x,y,cap,EDGE[x]); //������ʱ�߱�����ڽӱ�
        EDGE[y]=new((void *)tempedge++) edge(y,x,0,EDGE[y]);
        EDGE[x]->target=EDGE[y]; //����߱�
        EDGE[y]->target=EDGE[x];
    }
    while(RefreshDistLabel()) FindMaxFlow();
    printf("%lld\n",MAXTOTAL);
    return 0;
}
