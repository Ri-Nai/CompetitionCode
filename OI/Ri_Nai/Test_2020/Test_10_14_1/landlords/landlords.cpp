#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
typedef unsigned long long ULL;
int T,n,cnt[16],ans;
map<ULL,int>vis;
ULL chk()
{
	ULL now=1,res=0;
	for(int i=1;i<=14;++i)
		res+=cnt[i]*now,now*=5;
	return res;
}
void dfs(int);
void Sort(int k,int len,int stp)
{
	int Up=12-len+1;
	for(int i=1;i<=Up;++i)
	{
		int now=i;
		if(cnt[now]<k)continue;
		while(now<12&&cnt[now+1]>=k)++now;
		if(now-i+1>=len)
		{
			for(int j=i;j<=now;++j)cnt[j]-=k;
			for(int j=now;j>=i;--j)
			{
				if(j-i+1>=len)dfs(stp+1);
				cnt[j]+=k;
			}
		}
	}
}
void Three(int p,int stp)
{
	for(int i=1;i<=13;++i)
		if(cnt[i]>=3)
		{
			cnt[i]-=3;
			if(p==0)
			{
				dfs(stp+1);
				cnt[i]+=3;
				continue;
			}
			for(int j=1;j<=13;++j)
				if(cnt[j]>=p)cnt[j]-=p,dfs(stp+1),cnt[j]+=p;
			if(p==1&&cnt[14])--cnt[14],dfs(stp+1),++cnt[14];
			cnt[i]+=3;
		}
}
void Four(int p,int stp)
{
	for(int i=1;i<=13;++i)
		if(cnt[i]==4)
		{
			cnt[i]-=4;
			for(int j=1;j<=13;++j)
				if(cnt[j]>=p)
				{
					cnt[j]-=p;
					for(int k=j;k<=13;++k)
						if(cnt[k]>=p)
						{
							cnt[k]-=p;
							dfs(stp+1);
							cnt[k]+=p;
						}
					if(p==1&&cnt[14]==1)--cnt[14],dfs(stp+1),++cnt[14];
					cnt[j]+=p;
				}
			if(p==1&&cnt[14]==2)cnt[14]-=2,dfs(stp+1),cnt[14]+=2;
			cnt[i]+=4;
		}
}
void dfs(int stp)
{
	if(stp>=ans)return ;
	ULL stt=chk();
	if(stt==0){ans=stp;return ;}
	int k=vis[stt];
	if(k&&k<=stp)return;
	vis[stt]=stp;
	Sort(3,2,stp);
	Sort(2,3,stp);
	Sort(1,5,stp);
	Four(2,stp);
	Four(1,stp);
	Three(2,stp);
	Three(1,stp);//炸弹也是三带一 
	Three(0,stp);
	int now=0;
	for(int i=1;i<=14;++i)if(cnt[i])++now;
	if(now+stp>=ans)return;
	ans=stp+now;
}
void solve()
{
	ans=1e9;vis.clear();
	for(int i=1;i<=14;++i)cnt[i]=0;
	for(int i=1,p;i<=n;++i)
	{
		scanf("%d",&p);
		if(p==0)++cnt[14];
		else if(p==1||p==2)++cnt[p+11];
		else ++cnt[p-2];
		scanf("%d",&p);
	}
	dfs(0);
//	if(ans==0){for(int i=1;i<=14;++i)printf("%d ",cnt[i]);printf("\n%llu",chk());}
	printf("%d\n",ans);
}
int main()
{
//	FILE("landlords");
	cin>>T>>n;
	while(T--)solve();
	FCLS();
}
/*


*/
