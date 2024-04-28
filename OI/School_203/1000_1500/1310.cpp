#include<cmath>
#include<cstdio>
#include<cstring>
const int maxn=2e4+56;
int ans[maxn],tot,pr[maxn<<1][10],n,m,res[maxn];
bool mark[maxn];
void init()
{
	mark[0]=mark[1]=1;
	for(int i=2;i<=maxn;++i)
		if(!mark[i])for(int j=i;j<=maxn;j+=i)
			mark[j]=1,pr[j][++pr[j][0]]=i;
}
void Time(int x)
{
	for(int i=0;i<=tot;++i)ans[i]*=x;
	for(int i=0;i<=tot;++i)ans[i+1]+=ans[i]/10,ans[i]%=10;
	while(ans[tot+1]>0)++tot,ans[tot+1]+=ans[tot]/10,ans[tot]%=10;
}
void resolve(int x,int mark)
{
    for(int i=1;i<=x;++i)
    {
        int tmp=i;
        for(int j=1;j<=pr[i][0];++j)
            while(tmp%pr[i][j]==0)
                res[pr[i][j]]+=mark,
                tmp/=pr[i][j];
    }
}
int main()
{
	init();
	scanf("%d%d",&n,&m);ans[0]=1;
	resolve(n,1),resolve(m,-1),resolve(n-m,-1);
	for(int i=1;i<=10000;++i)
        while(res[i])Time(i),--res[i];
    for(int i=tot;~i;--i)
    	printf("%d",ans[i]);
}