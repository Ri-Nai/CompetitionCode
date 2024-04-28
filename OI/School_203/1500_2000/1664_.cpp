#include<bits/stdc++.h>
using namespace std;
const int N=1505;
int n,m;long long K;
struct Matrix
{
	bool M[N];
	Matrix(){memset(M,0,sizeof M);}
	Matrix operator * (const Matrix &_)const
	{
		Matrix res;
		for(int i=0;i<m;++i)if(M[i])
			for(int j=0;j<m;++j)if(_.M[j])
				res.M[i*j%m]=1;
		return res;
	}
	void Qpow(long long k)
	{
		Matrix tmp=*this;
		for(--k;k;k>>=1,tmp=tmp*tmp)
			if(k&1)*this=*this*tmp;
	}
}base;
int main()
{
	scanf("%lld%d%d",&K,&m,&n);
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),base.M[x]=1;
	base.Qpow(K);
	for(int i=0;i<m;++i)
		if(base.M[i])printf("%d ",i);
}