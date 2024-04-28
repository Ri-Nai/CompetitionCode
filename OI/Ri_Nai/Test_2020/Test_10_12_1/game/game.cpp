#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=1e6+5,mod=1e9;
int n,len;
struct Man
{
	int a,b;
	void read(){scanf("%d%d",&a,&b);}
	bool operator <(const Man &_)const
	{
		return a*b<_.a*_.b;
	}
}A[N];
struct Big
{
	int len;
	long long A[N];
	Big(){memset(A,0,sizeof A);len=1;}
	void Plus(int p)
	{
		for(int j=1;j<=len;++j)A[j]*=p;
		for(int j=1;j<=len;++j)A[j+1]+=A[j]/mod,A[j]%=mod;
		while(A[len+1])++len,A[len+1]+=A[len]/mod,A[len]%=mod;
	}
	void Copy(Big p)
	{
		memcpy(A,p.A,sizeof A);len=p.len;
	}
	void show()
	{
		printf("%lld",A[len]);
		while(--len)printf("%09lld",A[len]);
		puts("");
	}
	Big operator / (int p)const
	{
		Big res;
		long long rst=0;
		for(int i=len;i;--i)
		{
			rst=rst*mod+A[i];
			res.A[i]=rst/p;
			rst%=p;
		}
		for(int i=len;i;--i)
			if(res.A[i]){res.len=i;break;}
		return res;
	}
	void ToMax(Big p)
	{
		if(p.len<len)return ;
		bool flag=0;
		if(p.len==len)
		{
			for(int i=len;i;--i)
				if(p.A[i]>A[i]){flag=1;break;}
				else if(p.A[i]<A[i])break;
		}
		else flag=1;
		if(flag)Copy(p);
	}
}Sum,Ans;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;++i)A[i].read();
	sort(A+1,A+n+1);
	Sum.A[1]=A[0].a;
	for(int i=1;i<=n;++i)
		Ans.ToMax(Sum/A[i].b),Sum.Plus(A[i].a);
	Ans.show();
}
