#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5,inf=2e9;
typedef long long LL;
int n,m,H[N],X,S,nxt[N][20],NTA[N],NTB[N];
LL SmA[N][20],SmB[N][20];
struct pr
{
	int x,y,id;
	bool operator <(const pr &_)const
	{
		return x==_.x?y<_.y:x<_.x;
	}
}mn,mmn;
bool chk(LL MA,LL MB,LL SA,LL SB,int i,int id)
{
	if(MB==0&&SB!=0)return 1;
	if(MB==0&&SB==0)return H[i]>H[id];
	return 1ll*MA*SB>1ll*MB*SA;
}
struct Node
{
	int v,id;
	void read(int i){scanf("%d",&H[i]);id=i;v=H[i];}
	bool operator <(const Node &_)const{return v<_.v;}
}C[N];
int L[N],R[N];
inline int dis(int a,int b)
{
	if(b==n+1)return 0;
	return abs(H[a]-H[b]);
}
void make(int f,int p)
{
	if(p==0||p==n+1)return;
	pr now=(pr){dis(f,p),H[p],p};
	if(now<mn)mmn=mn,mn=now;
	else if(now<mmn)mmn=now;
}
void Travel(LL &SA,LL &SB,int S,int L)
{
	int now=S;
	for(int i=19;~i;--i)
		if(SA+SmA[now][i]+SB+SmB[now][i]<=L)
		{
			SA+=SmA[now][i];
			SB+=SmB[now][i];
			now=nxt[now][i];
		}
	if(SA+dis(now,NTA[now])+SB<=L)
		SA+=dis(now,NTA[now]);
}
int main()
{
	// FILE("drive");
	cin>>n;
	C[0].id=0;
	C[n+1].id=n+1;
	L[0]=0;R[n+1]=n+1;
	NTA[n+1]=NTB[n+1]=n+1;
	for(int i=1;i<=n;++i)C[i].read(i);
	sort(C+1,C+n+1);
	for(int i=1;i<=n;++i)
	{
		L[C[i].id]=C[i-1].id;
		R[C[i].id]=C[i+1].id;
	}
	for(int i=1;i<=n;++i)
	{
		mn=mmn=(pr){inf,inf,n+1};
		make(i,L[i]);make(i,L[L[i]]);
		make(i,R[i]);make(i,R[R[i]]);
		NTA[i]=mmn.id;NTB[i]=mn.id;
		R[L[i]]=R[i];L[R[i]]=L[i];
	}
	for(int i=1;i<=n;++i)
	{
		nxt[i][0]=NTB[NTA[i]];
		SmA[i][0]=dis(i,NTA[i]);
		SmB[i][0]=dis(NTA[i],NTB[NTA[i]]);
	}
	for(int i=1;i<20;++i)
		for(int j=1;j<=n;++j)
		{
			nxt[j][i]=nxt[nxt[j][i-1]][i-1];
			SmA[j][i]=SmA[j][i-1]+SmA[nxt[j][i-1]][i-1];
			SmB[j][i]=SmB[j][i-1]+SmB[nxt[j][i-1]][i-1];
		}
	cin>>X;
	int id=1;
	LL SA,SB,MA,MB;
	for(int i=1;i<=n;++i)
	{
		SA=0,SB=0;
		Travel(SA,SB,i,X);
		if(i==1||chk(MA,MB,SA,SB,i,id))
			MA=SA,MB=SB,id=i;
	}
	cout<<id<<endl;cin>>m;
	for(int i=1;i<=m;++i)
	{
		SA=0,SB=0;
		scanf("%d%d",&S,&X);
		Travel(SA,SB,S,X);
		printf("%lld %lld\n",SA,SB);
	}
}
/*
*/