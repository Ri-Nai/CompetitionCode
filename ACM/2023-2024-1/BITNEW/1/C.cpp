#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
const int M=1e6+5;
int p[M],pr[M],len;
void init()
{
    p[1]=-1;
    for(int i=2;i<M;++i)
        if(~p[i])
        {
            pr[p[i]=++len]=i;
            for(int j=i+i;j<M;j+=i)
                p[j]=-1;
        }

}
namespace T
{
    int a,b,c,d,n;
    struct Split
    {
        int cnt[M],is[M],tot;
        void Make(int a)
        {
            for(int i=1;i<=tot;++i)
                cnt[is[i]]=0;
            tot=0;
            for(int i=1;i<=len;++i)
            {
                if(a%pr[i]==0)
                {
                    is[++tot]=i;
                    while(a%pr[i]==0)
                        a/=pr[i],++cnt[i];
                }
                if(a<M and ~p[a])
                {
                    is[++tot]=p[a];
                    ++cnt[p[a]];
                    a=1;
                }
                if(a==1)return;
            }
        }
        void Show()
        {
            cout<<"**"<<tot<<'\n';
            for(int i=1;i<=tot;++i)
                cout<<is[i]<<' '<<pr[is[i]]<<' '<<cnt[is[i]]<<'\n';
        }

    }A,B,D;
    void solve()
    {
        cin>>a>>d>>n;
        A.Make(a);
        D.Make(d);
        // A.Show(),D.Show();
        for(int i=1;i<=D.tot;++i)
            if(D.cnt[D.is[i]]>A.cnt[D.is[i]])
                End("0");
        ll ans=0;
        for(b=1;b<=n;++b)
        {
            bool flag=0;
            B.Make(b);
            // for(int j=1;j<=B.tot;++j)
            //     if(A.cnt[B.is[j]]==0)
            //         flag=1;
            // if(flag)continue;
            ll res=1;
            // B.Show();
            for(int j=1;j<=A.tot;++j)
            {
                int t=A.is[j];
                int now=min(A.cnt[t],B.cnt[t]);
                // cout<<t<<' '<<pr[t]<<' '<<now<<' '<<B.cnt[t]<<'\n';
                if(now<D.cnt[t])
                {
                    res*=0;
                    break;
                }
                if(now==D.cnt[t])
                    res*=D.cnt[t]+1;
            }
            // cout<<b<<' '<<res<<'\n';
            ans+=res;
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    int t;cin>>t;while(t--)
    T::solve();

}
