#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5,M=N<<1;
    struct BIT
    {
        int n;
        ll C[M];
        BIT(int _)
        {
            n=_;
            for(int i=0;i<=_;++i)C[i]=0;
        }
        void Add(int x,ll y)
        {
            for(;x<=n;x+=x&-x)C[x]+=y;
        }
        ll Sum(int x)
        {
            ll res=0;
            for(;x;x-=x&-x)res+=C[x];
            return res;
        }
        void update(int l,int r,ll x)
        {
            Add(l,x);Add(r+1,-x);
        }
        ll query(int l,int r)
        {
            return Sum(r)-Sum(l-1);
        }
        void Show(int op)
        {
            for(int i=1;i<=n;++i)
                cout<<(op?Sum(i):query(i,i))<<' ';
            cout<<'\n';
        }

    };
    int n,m,tot,L[N],R[N];
    int W[N],X[N],num[N];
    ll P[N],A[M];
    map<ll,int>ord;
    vector<int>id[M];
    void init()
    {
        // BIT tmp(10);
        // tmp.Add(1,2);
        // cout<<tmp.Sum(0)<<' '<<tmp.Sum(1)<<' '<<tmp.Sum(2);
        cin>>n>>m;
        for(int i=1;i<=m;++i)
            cin>>W[i]>>X[i],A[i]=(P[W[i]]+=X[i]);
        sort(A+1,A+m+n+1);
        for(int i=1;i<=m+n;++i)
        {
            if(i==1 or A[i]!=A[i-1])
                ord[A[i]]=++tot;
            id[tot].push_back(i);
        }
        for(int i=1;i<=tot;++i)
        {
            L[i]=id[i].front(),R[i]=id[i].back();
            // cout<<L[i]<<' '<<R[i]<<'\n';
        }
        memset(P,0,sizeof P);
    }
    void solve()
    {
        init();
        BIT Cnt(n+m);
        BIT Val(n+m);
        // for(int i=1;i<=n;++i)
        // Cnt.Show();
        // Val.Show();
        // Val.update(1,1,1);
        // Val.Show(1);
        // Val.update(1,1,-Val.query(1,1));
        // Val.Show(1);
        for(int i=1,t=ord[0];i<=n;++i)
        {
            num[i]=id[t].back();
            Cnt.Add(num[i],1);
            id[t].pop_back();
        }
        for(int i=1;i<=m;++i)
        {
            int pre=num[W[i]];
            int t1=ord[P[W[i]]],t2=ord[P[W[i]]+=X[i]];
            int now=id[t2].back();
            id[t2].pop_back();
            num[W[i]]=now;
            if(X[i]==0)continue;
            // for(int i=1;i<=n+m;++i)
            //     cout<<ord[A[i]]<<' ';
            // cout<<'\n';
            // Cnt.Show(0);
            Cnt.Add(pre,-1);
            bool flag=0;
            if(t1>t2)swap(t1,t2),flag=1;//分数从高到低 位次从低到高
            //t1 存的是低分 t2 存的是高分
            int cnt=Cnt.query(R[t1]+1,R[t2]);
            ll lst=Val.Sum(pre);
            Cnt.Add(now,1);
            // Cnt.Show(0);
            // cout<<lst<<'\n';
            // Val.Show(1);
            Val.update(pre,pre,-lst);
            // Val.Show(1);
            Val.update(now,now,-Val.Sum(now));
            // Val.Show(1);
            Val.update(now,now,lst+cnt);
            // Val.Show(1);
            // cout<<"************"<<cnt<<'\n';
            Val.update(L[t1],L[t2]-1,1);
            if(flag)Val.update(now,now,-1);
        }
        for(int i=1;i<=n;++i)
        {
            // cout<<num[i]<<' ';
            cout<<Val.Sum(num[i])<<'\n';
        }
    }
}
bool Ri;
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    // cout<<(&Ri-&Nai)/8/1024./1024<<'\n';
    T::solve();

}
