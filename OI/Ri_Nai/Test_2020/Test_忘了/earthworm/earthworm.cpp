#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5;
bool Ri;
int n,m,q,u,v,t,A[N];
namespace P35
{
	// multiset<int>S;
	priority_queue<int>Q;
	void Solve()
	{
		for(int i=1;i<=n;++i)Q.push(A[i]);
		for(int i=1;i<=m;++i)
		{
			int p=Q.top();Q.pop();
			p+=(i-1)*q;
			if(i%t==0)printf("%d ",p);
			int k=1ll*u*p/v;
			Q.push(k-i*q);
			Q.push(p-k-i*q);
		}
		puts("");
		for(int i=1;!Q.empty();++i)
		{
			if(i%t==0)printf("%d ",Q.top()+m*q);
			Q.pop();
		}
		puts("");
	}
}
namespace P70
{
	const int M=7e6+5;
	int Tmp[M];
	struct Array
	{
		int A[M],L,R;
		Array(){L=1;R=0;}
		void push_back(int t){A[++R]=t;}
		int top(){return R>=L?A[L]:-1;}
		void pop(){++L;}
		void show(){for(int i=L;i<=R;++i)Rn_2(i,A[i]);}
		void ToLeft()
		{
			for(int i=L;i<=R;++i)A[i-L+1]=A[i];
			R=R-L+1;L=1;
		}
		void Merge(Array z)
		{
			int i=1,j=1,tot=0;
			while(i<=R&&j<=z.R)Tmp[++tot]=A[i]>z.A[j]?A[i++]:z.A[j++];
			while(i<=R)Tmp[++tot]=A[i++];
			while(j<=z.R)Tmp[++tot]=z.A[j++];
			for(int i=1;i<=tot;++i)A[i]=Tmp[i];R=tot;
		}
	}P,Q,R;//q=0 ï¿½ï¿½ ï¿½ï¿½ ï¿½ï¿½ ÌÌÌÌÌÌ 
	void Solve()
	{
		sort(A+1,A+n+1);
		for(int i=n;i>=1;--i)P.push_back(A[i]);
		for(int i=1;i<=m;++i)
		{
			int p;
			if(P.top()>=Q.top()&&P.top()>=R.top())p=P.top(),P.pop();
			else if(Q.top()>=P.top()&&Q.top()>=R.top())p=Q.top(),Q.pop();
			else p=R.top(),R.pop();
			int k1=1ll*u*p/v,k2=p-k1;
			if(i%t==0)printf("%d ",p);
			if(k1<k2)swap(k1,k2);
			Q.push_back(k1);
			R.push_back(k2);
		}
		P.ToLeft();Q.ToLeft();R.ToLeft();
		P.Merge(Q);P.Merge(R);puts("");
		for(int i=t;i<=n+m;i+=t)printf("%d ",P.A[i]);
	}
}
bool Nai;
int main()
{
//	printf("%f\n",(&Ri-&Nai)/1024./1024);
	FILE("earthworm");
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	if(q==0)P70::Solve();
	else P35::Solve();
	FCLS();
}
/*
100MB
3 7 1 1 3 1
3 3 2

3 7 1 1 3 2
3 3 2

3 7 1 1 3 9
3 3 2

2 3 0 1 2 1
5 3

3 8 0 1 2 1
9 9 6



q=0Ê± ´ð°¸µ¥µ÷²»µÝÔö
¿¼ÂÇ¹é²¢ 
*/
