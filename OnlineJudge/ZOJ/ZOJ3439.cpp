#include<queue>
#include<cstdio>
#include<cstring>
const int maxn=105,maxA=205,HD=1e9+7;
int pre[maxn*20][2],fail[maxn*20],tot;//AC
char s[25],A[205];
void clear()
{
	memset(pre,0,sizeof pre);
	memset(fail,0,sizeof fail);
	tot=0;
}
void Insert(char *s)
{
	int len=strlen(s),now=0;
	for(int i=0;i<len;++i)
	{
		int k=s[i]-48;
		if(!pre[now][k])
			pre[now][k]=++tot;
		now=pre[now][k];
	}
}
bool Find(char *s)
{
	int len=strlen(s),now=0;
	for(int i=0;i<len;++i)
	{
		int k=s[i]-48;
		if(!pre[now][k])return 0;
		now=pre[now][k];
	}	
	return 1;
}
void Build_Fail()
{
	std::queue<int>Q;
	int now=0;
	for(int i=0;i<2;++i)
	{
		int &nxt=pre[now][i];
		if(nxt)fail[nxt]=0,Q.push(nxt);
	}
	while(!Q.empty())
	{
		int now=Q.front();Q.pop();
		for(int i=0;i<2;++i)
		{
			int &nxt=pre[now][i];
			if(nxt)fail[nxt]=pre[fail[now]][i],Q.push(nxt);
			else nxt=pre[fail[now]][i];
		}
	}
}
void init(char *Num,bool minus)
{
	int len=strlen(Num+1);
	for(int i=1,j=len;i<j;++i,--j)
	{
		int t=Num[i];Num[i]=Num[j];Num[j]=t;
	}
	if(minus)
	{
		--Num[1];
		for(int i=1;i<len;++i)
			if(Num[i]<48)Num[i]+=10,--Num[i+1];
		while(Num[len]==48)Num[len]=0,--len;
	}
	for(int i=1;i<=len;++i)Num[i]-=48;
}
LL dfs(int pos,bool lmt)
{
	
}
LL work(char *Num,bool minus)
{
	init(Num,minus);
	return dfs(len,)
}
void solve()
{
	clear();int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%s",s),Insert(s);
	Build_Fail();
	scanf("%s",A+1);LL res1=work(A,1);
	scanf("%s",A+1);LL res2=work(A,0);
	printf("%lld\n",(res2-res1+HD)%HD);

}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}