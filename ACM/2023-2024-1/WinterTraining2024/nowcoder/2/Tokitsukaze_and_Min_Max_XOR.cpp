#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    struct Node
    {
        int nxt[2];
        int has;
        Node()
        {
            nxt[0]=nxt[1]=0;
            has=0;
        }
    };
    void solve()
    {
        const int mod=1e9+7;
        int n=rd(),k=rd();
        vector<Node>Trie(1);
        vector<int>A;
        for(int i=1;i<=n;++i)A.push_back(rd());
        sort(A.begin(),A.end());
        int ans=n;
        auto Qpow=[&](int n,int p)
        {
            int res=1;
            for(int x=n;p;x=1ll*x*x%mod,p>>=1)
                if(p&1)res=1ll*res*x%mod;
            return res;
        };
        auto insert=[&](int x)
        {
            int rt=0;
            for(int i=31;i>=0;--i)
            {
                int now=(A[x]>>i)&1;
                // cout<<i<<' '<<rt<<'\n';
                if(!Trie[rt].nxt[now])
                {
                    Trie.push_back(Node());
                    Trie[rt].nxt[now]=Trie.size()-1;
                }
                rt=Trie[rt].nxt[now];
                Trie[rt].has=(Trie[rt].has+Qpow(Qpow(2,x),mod-2))%mod;
            }
        };
        auto Query=[&](Node rt,int id,int y)
        {
            int x=A[id];

            for(int i=31;i>=0;--i)
            {
                int bx=(x>>i)&1;
                int by=(y>>i)&1;
                if(by)
                {
                    if(rt.nxt[bx])
                    {
                        ans=(ans+1ll*Qpow(2,id-1)*Trie[rt.nxt[bx]].has)%mod;
                    }
                    if(!rt.nxt[bx^1])return;
                    rt=Trie[rt.nxt[bx^1]];
                }
                else
                {
                    if(!rt.nxt[bx])return;
                    rt=Trie[rt.nxt[bx]];
                }
            }
            ans=(ans+1ll*Qpow(2,id-1)*rt.has)%mod;
        };
        for(int i=0;i<n;++i)
        {
            Query(Trie[0],i,k);
            insert(i);
        }
        cout<<ans<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
