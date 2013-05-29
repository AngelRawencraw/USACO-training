/*
ID: silentf1
PROG: buylow
LANG: C++
*/
#include<cstdio>
#include<cstring>
#define cprint printf
#define BIG 5005
#define MAX(a,b) ((a)>(b)?(a):(b))
struct elect{
    long ele[BIG],len;
    long MAXN(){return ele[len];}
    long refresh(long VAL){ele[++len]=VAL;return len;}
    long change(long VAL){  //���ֲ���
        long left=1,right=len,mid=(left+right)>>1;
        while(left<right)
            if(VAL>ele[mid]){
                left=mid+1;
                mid=(left+right)>>1;
            }
            else{
                right=mid;
                mid=(left+right)>>1;
            }
        ele[left]=VAL;
        return left;
    }
}num;
class Plus{
    int num[80],len;
    public:
    void refresh(){num[++len]=1;}
    friend Plus operator + (const Plus &A,const Plus &B){
        Plus C;
        int LEN=MAX(A.len,B.len);
        for(int i=1;i<=LEN;i++){
            C.num[i]+=A.num[i]+B.num[i];
            C.num[i+1]+=(C.num[i])/10;
            C.num[i]%=10;
        }
        if(C.num[LEN+1]!=0) C.len=++LEN;
            else C.len=LEN;
        return C;
    }
    void operator = (const Plus &A){
        memcpy(num,A.num,sizeof(A.num));
        len=A.len;
    }
    void print(){for(int i=len;i>=1;i--) cprint("%ld",num[i]);cprint("\n");}
    Plus(){memset(num,0,sizeof(num));len=0;}
}sum[BIG];
long val[BIG][2],n;
bool Find[BIG*10],flag;//Find��֤���ظ�����
Plus tot;
int main()
{
    freopen("buylow.in","r",stdin);
    freopen("buylow.out","w",stdout);
    scanf("%ld",&n);
    for(int i=1;i<=n;i++) scanf("%ld",&val[i][0]);
    for(int i=n;i>=1;i--)
        if(val[i][0]>num.MAXN()) val[i][1]=num.refresh(val[i][0]);
            else{if(val[i][0]<num.MAXN()) val[i][1]=num.change(val[i][0]);
                 else val[i][1]=num.len;}
    for(int i=n;i>=1;i--){
        flag=false;
        memset(Find,0,sizeof(Find));
        for(int j=i+1;j<=n;j++) //ע�����˳������еĵ�����
            if(!Find[val[j][0]] && val[i][1]==val[j][1]+1 && val[i][0]>val[j][0]){
                sum[i]=sum[i]+sum[j];
                Find[val[j][0]]=true;
                flag=true;
            }
        if(!flag) sum[i].refresh();//δ�ҵ�����ģ���Ϊ��ǰ��Сֵ����ʼ��Ϊ1
    }
    memset(Find,0,sizeof(Find));
    for(int i=n;i>=1;i--)
        if(!Find[val[i][0]] && val[i][1]==num.len){
            tot=tot+sum[i];
            Find[val[i][0]]=true;
        }
    /*
    ������һ���϶̵ĳ���:
    for(int i=n;i>=1;i--){
        flag=false;
        for(int j=n;j>=i+1;j--){
            if(!Find[j] && val[i][1]==val[j][1]+1 && val[i][0]>val[j][0] ){
                sum[i]=sum[i]+sum[j];
                flag=true;
            }
            else if(val[i][0]==val[j][0]) Find[j]=true;//�����ظ��������ǰ��
        }
        if(!flag) sum[i].refresh();//δ�ҵ�����ģ���ʼ��Ϊ1
    }
    for(int i=n;i>=1;i--) if(!Find[i] && val[i][1]==num.len) tot=tot+sum[i];
    */
    printf("%ld ",num.len);
    tot.print();
	return 0;
}
