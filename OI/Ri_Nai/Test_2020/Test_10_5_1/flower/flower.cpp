#include<bits/stdc++.h>
using namespace std;
#define LW(x) x=lower_bound(B+1,B+len+1,x)-B+1
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5;
int n,A[N],len,B[N],p,C1[N],C2[N];//<=x 存C1 | >=x存C2
void Add_1(int x,int y){while(x<=p)C1[x]=max(C1[x],y),x+=x&-x;}
void Add_2(int x,int y){while(x)C2[x]=max(C2[x],y),x^=x&-x;}
int Sum_1(int x){int res=0;while(x)res=max(res,C1[x]),x^=x&-x;return res;}
int Sum_2(int x){int res=0;while(x<=p)res=max(res,C2[x]),x+=x&-x;return res;}
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
int main()
{
    // FILE("flower");
    n=rd();
    for(int i=1;i<=n;++i)A[i]=B[i]=rd();
    sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;p=len+1;
    for(int i=1;i<=n;++i)
    {
    	LW(A[i]);
    	int Urs=Sum_1(A[i]-1),Drs=Sum_2(A[i]+1);
    	Add_1(A[i],Drs+1),Add_2(A[i],Urs+1);
    }
    printf("%d\n",max(1,max(Sum_1(p),Sum_2(1))));
    FCLS();
}
/*
记录结束的点的权值
用BIT维护比v小的最大dp值
10
6 4 8 4 8 9 2 2 1 5 
6 4 8 4 8 2 5
*/