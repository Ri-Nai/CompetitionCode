#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
const int maxn=5e4+5,maxb=205;
int n,m,S,tot,A[maxn],blk[maxn],B[maxn],num[maxb][maxn]
,M[maxb][maxb],val[maxn],cnt[maxn],sum[maxb][maxn];
std::vector<int>V[maxn];
int read()
{
	int t=0,c;
	do c=getchar();while(c>57||c<48);
	while(c<=57&&c>=48)t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
void pre(int x)
{   
    memset(cnt,0,sizeof(cnt));
    int mx=0,ans=0;
    for(int i=(x-1)*S+1;i<=n&&i<=x*S;++i)++num[x][A[i]];
    for(int i=(x-1)*S+1;i<=n;++i)
    {
        ++cnt[A[i]];
        int t=blk[i];
        if(cnt[A[i]]>mx||(cnt[A[i]]==mx&&val[A[i]]<val[ans]))
            ans=A[i],mx=cnt[A[i]];
        M[x][t]=ans;
    }
}
int query(int l,int r)
{
	memset(cnt,0,sizeof cnt);
    if(blk[l]==blk[r])
    {
		int ans=M[blk[l]][blk[r]];
		for(int i=l;i<=r;++i)
		{
			++cnt[A[i]];
			int p1=cnt[ans];
			int p2=cnt[A[i]];
			if(p2>p1)ans=A[i];
			else if(p2==p1&&A[i]<ans)ans=A[i];
		}
		return ans;
		
	}
	else
	{
		int ans=M[blk[l]+1][blk[r]-1];
		for(int i=l;i<=blk[l]*S;++i)
		{
			cnt[A[i]]++;
			int p1=sum[blk[r]-1][ans]-sum[blk[l]][ans]+cnt[ans];
			int p2=sum[blk[r]-1][A[i]]-sum[blk[l]][A[i]]+cnt[A[i]];
			if(p2>p1)ans=A[i];
			else if(p2==p1&&A[i]<ans)ans=A[i];
		}
		for(int i=blk[r]*S-S+1;i<=r;++i)
		{
			cnt[A[i]]++;
			int p1=sum[blk[r]-1][ans]-sum[blk[l]][ans]+cnt[ans];
			int p2=sum[blk[r]-1][A[i]]-sum[blk[l]][A[i]]+cnt[A[i]];
			if(p2>p1)ans=A[i];
			else if(p2==p1&&A[i]<ans)ans=A[i];
		}
		return ans;
	}
}
int main()
{
    n=read();m=read();
    int ans=0;S=sqrt(n);
    for(int i=1;i<=n;++i)A[i]=read(),B[i]=val[i]=A[i];
    std::sort(B+1,B+n+1);int len=std::unique(B+1,B+n+1)-B;
	for(int i=1;i<=n;++i)
	{
		A[i]=std::lower_bound(B+1,B+len,A[i])-B;
		// printf("%d\n",A[i]);
		val[A[i]]=B[A[i]];
		blk[i]=(i-1)/S+1;
		V[A[i]].push_back(i);
	}
    for(int i=1;i<=blk[n];++i)pre(i);
    for(int i=1;i<=blk[n];++i)
    {
    	for(int j=1;j<len;++j)
    		sum[i][j]=sum[i-1][j]+num[i][j];
    }
    for(int i=1,l,r;i<=m;++i)
    {
    	l=read();r=read();
        l=(l+ans-1)%n+1;r=(r+ans-1)%n+1;
        if(l>r)std::swap(l,r);
        ans=val[query(l,r)];
        printf("%d\n",ans);
    }
}