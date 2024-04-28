#include<cstdio>
#include<cstring>
#define CLEAR(a) memset(a,0,sizeof a)
const int maxn=1e5+10;
const long long mod=1e10;
char s1[maxn],s2[maxn];
int n,fa[maxn],len[26],id[26];
int len1,len2,len3,L,A[maxn],B[maxn];
unsigned long long ans[1005];bool mark[maxn],vis[maxn];
bool flag;
void work(int cnt)
{
	for(int i=1;i<=L;++i)ans[i]<<=cnt;
	for(int i=1;i<=L;++i)if(ans[i]>=mod)ans[i+1]+=ans[i]/mod,ans[i]%=mod,L+=i==L;
}
void Add(int cnt)
{
	while(cnt>=30)cnt-=30,work(30);if(cnt)work(cnt);
}
void Clear()
{
	CLEAR(ans);CLEAR(mark);flag=0;
	L=1;ans[1]=1;CLEAR(vis);
}
int find(const int &x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int make_id(char *s,int *A,int l)
{
	int tot=0;
	for(int i=1;i<=l;++i)
	{
		if(s[i]=='0'||s[i]=='1')A[++tot]=s[i]-'0';
		else 
		{
			if(s[i]-'a'>=n)flag=1;
			for(int j=1;j<=len[s[i]-'a'];++j)
				A[++tot]=j+id[s[i]-'a'],vis[j+id[s[i]-'a']]=1;
		}
	}
	return len3=tot;
}
void init()
{
	Clear();
	for(int i=0;i<maxn;++i)fa[i]=i;
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&len[i]);id[0]=1;
	for(int i=1;i<n;++i)id[i]=id[i-1]+len[i-1];
	scanf("%d%s%d%s",&len1,s1+1,&len2,s2+1);
	if(make_id(s1,A,len1)!=make_id(s2,B,len2))flag=1;
}
void solve()
{
	init();
	for(int i=1;i<=len3;++i)
		if(find(A[i])!=find(B[i]))
			fa[find(A[i])]=find(B[i]);
	if(find(0)==find(1)||flag){puts("0");return;}
	mark[find(0)]=mark[find(1)]=1;int cnt=0;
	for(int i=2;i<=id[n-1]+len[n-1];++i)
		if(vis[i]&&!mark[find(i)])mark[find(i)]=1,++cnt;
	Add(cnt);printf("%lld",ans[L]);
	for(int i=L-1;i;--i)printf("%010llu",ans[i]);puts("");
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}