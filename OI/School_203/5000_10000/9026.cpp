#include<map>
#include<cstdio>
#include<cstring>
#include<iostream> 
#include<algorithm>
using namespace std;
const int N=1e4+5;
#define LW(x) x=lower_bound(B+1,B+len+1,x)-B
int K,n,V[N],U[N],W[N],ans[N],B[N],dis[N],len;
int main()
{
	scanf("%d%d",&K,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&V[i],&U[i]);
		if(V[i]>U[i])swap(V[i],U[i]);
		W[i]=-min(U[i]-V[i]+1,K);
		B[++len]=U[i];B[++len]=V[i];
	}
	sort(B+1,B+len+1);len=unique(B+1,B+len+1)-1-B;
	for(int i=1;i<=n;++i)LW(U[i]),LW(V[i]);
	for(int i=1;i<len;++i)
		U[++n]=i+1,V[n]=i,W[n]=0,
		U[++n]=i,V[n]=i+1,W[n]=B[i+1]-B[i]+1;
	for(int i=1;i<=len;++i)U[++n]=0,V[n]=i,W[n]=0;
	memset(dis,0x3f,sizeof dis);dis[0]=1e6;
	for(int i=1;i<len;++i)
		for(int j=1;j<=n;++j)
			dis[V[j]]=min(dis[V[j]],dis[U[j]]+W[j]);
	int tot=0,now=0;
    for(int i=2;i<=len;++i)
    {
        now=dis[i]-dis[i-1];
        for(int j=B[i]-now+1;now--;++j)ans[++tot]=j;
    }
    printf("%d\n",tot);
    for(int i=1;i<=tot;++i)printf("%d\n",ans[i]);
}