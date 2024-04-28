#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5,mod=99999997;
int C[N],n,D[N],pos[N];
long long ans;
struct CP
{
	int id,v;
	void read(int i)
	{
		id=i;scanf("%d",&v);
	}
	bool operator <(const CP &_)const
	{
		return v<_.v;
	}
}A[N],B[N];
void Add(int x,int y)
{
	while(x<=n)C[x]+=y,x+=x&-x;
}
int Sum(int x)
{
	int res=0;
	while(x)res+=C[x],x^=x&-x;
	return res;
}
int main()
{
	// FILE("match");
	scanf("%d",&n);
	for(int i=1;i<=n;++i)A[i].read(i);
	for(int i=1;i<=n;++i)B[i].read(i);
	sort(A+1,A+n+1);sort(B+1,B+n+1);
	for(int i=1;i<=n;++i)pos[A[i].id]=i;
	for(int i=1;i<=n;++i)
	{
		ans+=i-Sum(B[pos[i]].id)-1;
		Add(B[pos[i]].id,1);
	}
	printf("%lld\n",ans%mod);
	FCLS();
}
/*

*/