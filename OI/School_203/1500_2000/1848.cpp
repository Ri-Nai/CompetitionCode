#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#define R register
#define pr pair<int,int>
#define mp make_pair
const int M=1e7+5;
int val[M],P[M],n,mx,fa[M];bool id[M];
vector<pr>E[M];
int find(int u)
{
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
int rd()
{
	int t=0,c;do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
int main()
{
    n=rd();
    for(R int i=1;i<=n;++i)mx=max(P[i]=rd(),mx),val[P[i]]=P[i],id[P[i]]=1;
    if(id[1])puts("0"),exit(0);n=0;
    for(R int i=mx;i>=1;--i)
    {
    	if(!val[i])val[i]=val[i+1];
    	else ++n;fa[i]=i;
    }
    for(R int i=2;i<=mx;++i)if(id[i])
    {
        if(val[i+1]&&val[i+1]<i+i)
        	E[val[i+1]-i].push_back(mp(i,val[i+1]));
        for(R int j=2*i;j<=mx;j+=i)
        	if(val[j]&&val[j]<j+i)E[val[j]-j].push_back(mp(i,val[j]));
    }
    long long ans=0;int cnt=n-1;
    for(R int i=0;i<=mx;++i)
    {
        for(R int j=0;j<E[i].size();++j)
        {
            int u=find(E[i][j].first),v=find(E[i][j].second);
            if(u==v)continue;
            fa[u]=v,ans+=i;--cnt;
            if(!cnt)printf("%lld\n",ans),exit(0);
        }
    }
}