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
    ll Res[M];
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
        cin>>a>>n;
        A.Make(a);
        // A.Show(),D.Show();
        ll ans=0;
        // for(int i=1;i<=n;++i)Res[i]=0;
        for(b=n;b>=1;--b)
        {
            if(Res[b])
            {
                ans+=Res[b];
                continue;
            }
            B.Make(b);
            ll res=1;
            for(int j=1;j<=A.tot;++j)
            {
                int t=A.is[j];
                int now=min(A.cnt[t],B.cnt[t]);
                res*=(2*now+1);
            }
            for(int j=1;j<=A.tot;++j)
            {
                c=b;
                int t=A.is[j];
                int now=min(A.cnt[t],B.cnt[t]);
                for(int i=1;c%pr[t]==0;++i)
                {
                    if(Res[c])break;
                    int pre=min(A.cnt[t],B.cnt[t]-i);
                    Res[c/pr[t]]=res/(2*now+1)*(2*pre+1);
                    c/=pr[t];
                }
            }
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
