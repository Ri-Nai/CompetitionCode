#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int q,n,ans[N];
    struct Query
    {
        int d,l,r,id;
        void input(int i)
        {
            cin>>d>>l>>r;
            id=i;
        }
        bool operator <(const Query&_)const
        {
            return d<_.d;
        }
    }Q[N];
    struct BIT
    {
        int C[N];
        void clear(){for(int i=1;i<=n;++i)C[i]=0;}
        void Add(int x,int y)
        {
            while(x<=n)C[x]+=y,x+=x&-x;
        }
        int Sum(int x)
        {
            int res=0;
            while(x)res+=C[x],x-=x&-x;
            return res;
        }
    }T;
    int A[N];
    void solve()
    {
        string s;
        cin>>s;
        n=s.size();
        T.clear();
        cin>>q;
        for(int i=1;i<=q;++i)Q[i].input(i);
        sort(Q+1,Q+q+1);
        queue<int>que;
        for(int i=0;i<n;++i)
        {
            A[i+1]=s[i]-48;
            if(A[i+1]==1)
                que.push(i+1),T.Add(i+1,1);
        }
        int now=1;
        for(int i=1;i<=q;++i)
        {
            auto [d,l,r,id]=Q[i];
            while(now<d and !que.empty())
            {
                ++now;
                vector<int>nxt;
                while(!que.empty())
                {
                    // cout<<now<<'\n';
                    int u=que.front();
                    que.pop();
                    if(u-1>=1 and !A[u-1])
                    {
                        A[u-1]=1;
                        T.Add(u-1,1);
                        nxt.push_back(u-1);
                    }
                    if(u+1<=n and !A[u+1])
                    {
                        A[u+1]=1;
                        T.Add(u+1,1);
                        nxt.push_back(u+1);
                    }
                }
                for(int u:nxt)que.push(u);
            }
            ans[id]=T.Sum(r)-T.Sum(l-1);
        }
        for(int i=1;i<=q;++i)cout<<ans[i]<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
