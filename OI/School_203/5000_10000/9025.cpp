#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e4+5;
struct Decar
{
	int id,val,wt;
	Decar(){id=0;}
	bool operator < (const Decar &_)const
	{
		return val<_.val;
	}
	void read(int i)
	{
		scanf("%d%d",&val,&wt);id=i;
	}
}A[N];
struct Tre
{
	int ls,rs,fa;
	Tre(){ls=rs=fa=0;}
	Tre(int _,int __,int ___){ls=_,rs=__,fa=___;}
	void show(){printf("%d %d %d\n",A[fa].id,A[ls].id,A[rs].id);}
}B[N],ans[N];
int n,stk[N],top;
void Insert(int u)
{
	int Rt=-1;
	while(top&&A[stk[top]].wt>A[u].wt)Rt=stk[top--];
	B[stk[top]].rs=u;B[u].fa=stk[top];stk[++top]=u;
	if(Rt!=-1)B[Rt].fa=u,B[u].ls=Rt;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)A[i].read(i);
	sort(A+1,A+n+1);
	for(int i=1;i<=n;++i)Insert(i);
	for(int i=1;i<=n;++i)ans[A[i].id]=B[i];
	puts("YES");
	for(int i=1;i<=n;++i)ans[i].show();
}