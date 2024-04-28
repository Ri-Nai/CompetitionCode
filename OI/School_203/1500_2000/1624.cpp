#include<bits/stdc++.h>
using namespace std;
const int M=1e9;
bool p[M/50];int K,P;void solve1();void solve2();
int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
bool check(int t,int q)
{
	int res=0;
	for(int i=0;i<1<<q;++i)
	{
		bool flag=0;int tot=1;
		for(int j=0;j<q;++j)
			if(1<<j&i)flag^=1,tot*=pr[j];
		res+=t*(flag?-1:1)/tot;
	}
	return res>=K;
}
int main()
{
	cin>>K>>P;
	if(1ll*K*P>M)puts("0");
	else if(P>=53)solve1();
	else solve2();
}
void solve1()
{
	int q=M/P;
	for(int i=2;i<P;++i)if(!p[i])
		for(int j=i;j<=q;j+=i)p[j]=1;
	for(int i=1;i<=q;++i)if(!p[i])
		if(!--K)return (void)printf("%d\n",i*P);
	puts("0");
}
void solve2()
{
	int q=lower_bound(pr,pr+16,P)-pr,L=1,R=M/P,mid,ans=0;
	while(L<=R)
	{
		mid=L+R>>1;
		if(check(mid,q))R=(ans=mid)-1;
		else L=mid+1;
	}
	printf("%d\n",ans*P);
}