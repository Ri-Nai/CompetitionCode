#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=555,M=10;const LL inf=1e18;
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int n,m,K,tx,ty,X[M],Y[M],D[M],SL[M][N][N];
int Dir[265],cnt[M],Tm[M][M],Len[M];
bool vis[M][N][N];
LL K_[N],B_[N],B[N],ans=inf;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
void Exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b)Exgcd(b,a%b,y,x),y-=a/b*x;
	else x=1,y=0;
}
bool ExCRT(LL &k1,LL k2,LL &b1,LL b2)
{
	LL d=b1-b2,G=gcd(k2,k1),L=k1/G*k2,x,y;
	if(d%G)return 1;d/=G;Exgcd(k2,k1,x,y);
	b1=((b2+k2*(d*x%k1))%L+L)%L,k1=L;
	return 0;
}
inline bool pd(int x,int y)
{
	return x<=n&&y<=m&&x>=1&&y>=1;
}
void Move(int &x,int &y,int &d,int SL[N][N])
{
	if(SL[x][y])d=(d+SL[x][y])&3;
	if(!pd(x+dx[d],y+dy[d]))d^=2;
	x+=dx[d],y+=dy[d];
}
void GetAns()
{
	for(int i=1;i<=K;++i)K_[i]=Len[i],B_[i]=B[i];
	for(int i=2;i<=K;++i)
		if(ExCRT(K_[i],K_[i-1],B_[i],B_[i-1]))
			return;
	B_[K]=(B_[K]%K_[K]+K_[K])%K_[K];
	ans=min(ans,B_[K]+10000);
}
void dfs(int id)
{
	if(id==K+1)return GetAns();
	for(int i=1;i<=cnt[id];++i)
		B[id]=Tm[id][i],dfs(id+1);
}
int main()
{
	Dir['D']=0;Dir['L']=1;
	Dir['U']=2;Dir['R']=3;
	scanf("%d %d %d",&n,&m,&K);
	scanf("%d %d",&tx,&ty);
	for(int i=1;i<=K;++i)
	{
		char d[N];
		scanf("%d %d %s",&X[i],&Y[i],d);
		D[i]=Dir[*d];
		for(int j=1;j<=n;++j)
		{
			scanf("%s",d);
			for(int k=1;k<=m;++k)
				SL[i][j][k]=(d[k-1]-'0')&3;
		}
	}
	for(int i=1;i<=10000;++i)//暴力寻找答案
	{
		bool flag=1;
		for(int j=1;j<=K;++j)if(X[j]!=tx||Y[j]!=ty){flag=0;break;}
		if(flag)return printf("%d\n",i),0;
		for(int j=1;j<=K;++j)Move(X[j],Y[j],D[j],SL[j]);
	}
	for(int i=1;i<=K;++i)
	{
		memset(vis,0,sizeof(vis));
		int &x=X[i],&y=Y[i],&d=D[i];
		for(int j=0;;++j)
		{
			if(vis[d][x][y]){Len[i]=j;break;}
			vis[d][x][y]=1;
			if(x==tx&&y==ty)Tm[i][++cnt[i]]=j+1;
			Move(x,y,d,SL[i]);
		}
	}
	dfs(1);
	printf("%lld\n",ans==inf?-1:ans);
}