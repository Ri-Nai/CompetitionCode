#include<cstdio>
#include<algorithm>
const int maxn=2e5+5;
int n,m,A[maxn];
bool check(int T)
{
	int sum=0,p=1;
	for(int i=1;i<=n;++i)
	{
		if(A[i]>T)return 0;
		if(sum+A[i]>T)sum=0,++p;
		if(p>m)return 0;
		sum+=A[i];
	}
	//if(p>m)return 0;
	return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&A[i]);
    int l=1,r=1e9,ans=-1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
}