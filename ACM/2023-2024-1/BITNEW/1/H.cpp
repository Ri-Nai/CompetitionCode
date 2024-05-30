// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define End(X) return cout<<X<<'\n',void()

// namespace T
// {
//     const int N=3e5+5;
//     int n,m,tot;
//     int lastread[N],A[N];
//     int last;
//     int nxt[N],lst[N],head[N],val[N];
//     bool mark[N];
//     void Add(int x,int i)
//     {
//         if(!head[x])
//             head[x]=i;
//         else
//             nxt[lst[x]]=i;
//         lst[x]=i;
//         A[i]=x;
//     }
//     void solve()
//     {
//         cin>>m>>n;
//             // cout<<"aaa";
//         int ans=0;
//         for(int i=1;i<=n;++i)
//         {
//             int op,x;
//             cin>>op>>x;
//             // cout<<op<<' '<<x<<'\n';
//             if(op==1)Add(x,++tot);
//             if(op==2)
//             {
//                 for(int i=head[x];i;i=nxt[i])
//                     ans+=!mark[i],mark[i]=1;
//                 head[x]=0;
//             }
//             if(op==3)
//             {
//                 for(int i=last+1;i<=x;++i)
//                     ans+=!mark[i],mark[i]=1;
//                 last=max(last,x);
//             }
//             // cout<<tot<<' '<<ans<<'\n';
//             // cout<<tot<<' '<<has.count()<<'\n';
//             cout<<tot-ans<<'\n';
//         }

//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     // int t;cin>>t;while(t--)
//     T::solve();

// }
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()

namespace T
{
    const int N=3e5+5;
    bool has[N];
    int n,m,tot;
    int lastread[N],A[N];
    int last,ans;
    vector<int>V[N];
    void Set(int x)
    {
        ans+=!has[x];
        has[x]=1;
    }
    void solve()
    {
        cin>>m>>n;
            // cout<<"aaa";
        for(int i=1;i<=n;++i)
        {
            int op,x;
            cin>>op>>x;
            // cout<<op<<' '<<x<<'\n';
            if(op==1)
                {V[x].push_back(++tot);A[tot]=x;}
            if(op==2)
            {
                for(int i=lastread[x];i<V[x].size();++i)
                    Set(V[x][i]);
                lastread[x]=V[x].size();
            }
            if(op==3)
            {
                for(int i=last+1;i<=x;++i)
                    Set(i);
                last=max(last,x);
            }
            // cout<<tot<<' '<<has.count()<<'\n';
            cout<<tot-ans<<'\n';
        }

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
