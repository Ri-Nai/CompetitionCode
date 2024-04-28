#include<bits/stdc++.h>
using namespace std;
struct Rd
{
    Rd operator >> (int &t)const
    {
    	t=0;char c;int f=1;
	    while(!isdigit(c=getchar()))c=='-'&&(f=-1);
	    do t=(t<<3)+(t<<1)+(c^48);while(isdigit(c=getchar()));
	    t*=f;return *this;
    }
}CIN;
const int N=10005;const double eps=1e-11;
double K[N],E[N],A[N],B[N],C[N];bool flag;
int n,head[N],to[N<<1],nxt[N<<1],in[N],tot;
bool is0(double p){return p<=eps&&p>=-eps;}
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	++in[to[head[u]=tot]=v];
}
void Fly(int u,int f)
{
	if(flag)return;
	double p=(1.0-K[u]-E[u]),k=1;
	A[u]=K[u];C[u]=p;B[u]=p/=in[u];
	for(int i=head[u],v;v=to[i];i=nxt[i])if(v!=f)
	{
		Fly(v,u);if(flag)return ;
		k-=p*B[v],A[u]+=p*A[v],C[u]+=p*C[v];
	}
	if(is0(k))return (void)(flag=1);
	A[u]/=k;B[u]/=k;C[u]/=k;
}
void solve(int Cas)
{
	CIN>>n;flag=0;tot=0;
	memset(in,0,sizeof in);
	memset(head,0,sizeof head);
	for(int i=1,u,v;i<n;++i)
		CIN>>u>>v,Add(u,v),Add(v,u);
	for(int i=1,k,e;i<=n;++i)
		CIN>>k>>e,K[i]=k/100.0,E[i]=e/100.0;
	Fly(1,0);flag|=is0(1-A[1]);printf("Case %d: ",Cas);
	flag?puts("impossible"):printf("%.10f\n",C[1]/(1-A[1]));
}
int main()
{
	int T;CIN>>T;
	for(int i=1;i<=T;++i)solve(i);
}