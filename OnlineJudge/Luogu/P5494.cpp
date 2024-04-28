#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
	const int N=2e5+5;
	const int M=N*20;
	int n,m;
	ll T[M];
	int id,num=1,ls[M],rs[M],rt[N];
	inline void Pushup(int p)
	{
		T[p]=T[ls[p]]+T[rs[p]];
	}
	void Upd(int &p,int x,int y,int L=1,int R=n)
	{
		if(!p)p=++id;
		if(L==R)
		{
			T[p]+=y;
			return ;
		}
		int mid=L+R>>1;
		if(x<=mid)Upd(ls[p],x,y,L,mid);
		else Upd(rs[p],x,y,mid+1,R);
		Pushup(p);
	}
	void Merge(int &p,int q,int L=1,int R=n)
	{
		if(!q)return;
		if(!p){p=q;return;}
		if(L==R)
		{
			T[p]+=T[q];
			return ;
		}
		int mid=L+R>>1;
		Merge(ls[p],ls[q],L,mid);
		Merge(rs[p],rs[q],mid+1,R);
		Pushup(p);
	}
	void Split(int &p,int &q,int l,int r,int L=1,int R=n)
	{
		if(!p)return;
		if(l==L and r==R)
		{
			q=p;
            p=0;
			return;
		}
		if(!q)q=++id;
		int mid=L+R>>1;
		if(r<=mid)Split(ls[p],ls[q],l,r,L,mid);
		else if(l>mid)Split(rs[p],rs[q],l,r,mid+1,R);
		else Split(ls[p],ls[q],l,mid,L,mid),Split(rs[p],rs[q],mid+1,r,mid+1,R);
		Pushup(p);
		Pushup(q);
	}
	ll Query(int p,int l,int r,int L=1,int R=n)
	{
		if(!p)return 0;
		if(l==L and r==R)return T[p];
		int mid=L+R>>1;
		if(r<=mid)return Query(ls[p],l,r,L,mid);
        if(l>mid)return Query(rs[p],l,r,mid+1,R);
		return Query(ls[p],l,mid,L,mid)+Query(rs[p],mid+1,r,mid+1,R);
	}
	int Kth(int p,ll k,int L=1,int R=n)
	{
		if(L==R)return L;
		int mid=L+R>>1;
		ll m=T[ls[p]];
		if(k<=m)return Kth(ls[p],k,L,mid);
		else return Kth(rs[p],k-m,mid+1,R);
	}
    void solve()
    {
		cin>>n>>m;
		for(int i=1;i<=n;++i)
		{
			int x;cin>>x;
			if(!x)continue;
            Upd(rt[num],i,x);
		}
		for(int i=1;i<=m;++i)
		{
			int op,p;
            ll x,y;
			cin>>op;
			if(op==0)
			{
				cin>>p>>x>>y;
				Split(rt[p],rt[++num],x,y);
			}
			if(op==1)
			{
				cin>>p>>x;
				Merge(rt[p],rt[x]);
			}
			if(op==2)
			{
				cin>>p>>x>>y;
				Upd(rt[p],y,x);
			}
			if(op==3)
			{
				cin>>p>>x>>y;
				cout<<Query(rt[p],x,y)<<'\n';
			}
			if(op==4)
			{
				cin>>p>>x;
                if(x>T[rt[p]])cout<<"-1\n";
				else cout<<Kth(rt[p],x)<<'\n';
			}
		}
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();
}
