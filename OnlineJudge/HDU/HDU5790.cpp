#include<bits/stdc++.h>
using namespace std;
#define mid (L+R>>1)
const int maxn=1e5+5,maxm=4e6+5;
int n,m,A[maxn],B[maxn],cnt,Trie[maxn][26],num,st[maxn];
int tot,RT[maxn],ls[maxm],rs[maxm],pre[maxn],sum[maxm];
char s[maxn];
void build(int L,int R,int &rt)
{
	rt=++tot;sum[rt]=0;if(L==R)return;
	build(L,mid,ls[rt]);build(mid+1,R,rs[rt]);
}
void updata(int L,int R,int x,int y,int ot,int &rt)
{
	rt=++tot;sum[rt]=sum[ot]+y;
	ls[rt]=ls[ot];rs[rt]=rs[ot];
	if(L==R)return;
	if(x<=mid)updata(L,mid,x,y,ls[ot],ls[rt]);
	else updata(mid+1,R,x,y,rs[ot],rs[rt]);
}
long long query(int L,int R,int l,int r,int rt)
{
	if(L==l&&r==R)return sum[rt];
	if(r<=mid)return query(L,mid,l,r,ls[rt]);
	else if(l>mid)return query(mid+1,R,l,r,rs[rt]);
	return query(L,mid,l,mid,ls[rt])+query(mid+1,R,mid+1,r,rs[rt]);
}
int Insrt(char *s)
{
	int len=strlen(s),now=0;
	for(int i=0;i<len;++i)
	{
		int id=s[i]-'a';
		if(!Trie[now][id])Trie[now][id]=++num;
		now=Trie[now][id];
		A[++cnt]=now;
	}
	return cnt;
}
void solve()
{
	memset(pre,0,sizeof pre);
	memset(Trie,0,sizeof Trie);
	cnt=num=tot=0;
	for(int i=0;i<n;++i)
		scanf("%s",s),B[i]=Insrt(s);
	build(1,cnt,RT[0]);
	for(int i=1,tmp;i<=cnt;++i)
	{
		if(!pre[A[i]])
			updata(1,cnt,i,1,RT[i-1],RT[i]);
		else
			updata(1,cnt,pre[A[i]],-1,RT[i-1],tmp),
			updata(1,cnt,i,1,tmp,RT[i]);
		pre[A[i]]=i;
	}
	scanf("%d",&m);
	long long ans=0;
	while(m--)
	{
		int l,r;scanf("%d%d",&l,&r);
		l=(l+ans)%n;r=(r+ans)%n;
		if(r<l)swap(l,r);r=B[r];
		if(l>0)l=B[l-1];else l=0;
		printf("%lld\n",ans=query(1,cnt,l+1,r,RT[r]));
	}
}
int main()
{
	while(~scanf("%d",&n))solve();
}