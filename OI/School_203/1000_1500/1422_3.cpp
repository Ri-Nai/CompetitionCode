#include<cstdio>
#include<cstring>
#include<algorithm>
int const maxn=205;
int n,h,k,d[maxn],t[maxn],f[maxn],ans,Sum[maxn],T[maxn];
int main()
{
    scanf("%d%d",&n,&h);h*=12;
    for(int i=1;i<=n;++i)scanf("%d",&f[i]);
    for(int i=1;i<=n;++i)scanf("%d",&d[i]);
    for(int i=2;i<=n;++i)scanf("%d",&t[i]);
    for(int i=1;i<=n;++i)
    {
        int now=0;h-=t[i];
       	int pos1=0,pos2=1;
        //for(int i=1;i<=h;++i)TT[i]=f[i]-i*d[i]+d[i];
        for(int j=1;j<=h;++j)
        {
        	if(f[i]-pos1*d[i]>Sum[pos2])now+=T[j]=f[i]-pos1*d[i],++pos1;
        	else now+=T[j]=Sum[pos2++];
        }
       	memcpy(Sum,T,sizeof Sum);
        ans=std::max(ans,now);
    }
    printf("%d\n",ans);
} 