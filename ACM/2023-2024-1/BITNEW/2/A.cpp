#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int P=1e9+7;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    int m,n;
    const int N=1e4+5,M=1e3+5;
    // map<ull,int>mp;
    struct Pr
    {
        ull val;
        int id;
        Pr(ull _,int __){val=_,id=__;}
        bool operator <(const Pr&_)const
        {
            return val<_.val;
            // return id<_.id;
        }
    };
    char s[N][M];
    int len[N];
    set<Pr>S;
    set<ull>fw;
    void solve()
    {
        cin>>m>>n;
        long long ans=0;
        // while(m--)
        for(int j=1;j<=m;++j)
        {
            cin>>s[j]+1;
            ull hsh=0;
            bool flag=0;
            for(int i=1;i<=n;++i)
            {
                hsh=hsh*P+s[j][i];
                auto it=S.find(Pr(hsh,0));
                auto tt=fw.find(hsh);
                if(tt!=fw.end())continue;
                if(it==S.end())
                {
                    S.insert(Pr(hsh,j));
                    len[j]=i;
                    ans+=i;
                    break;
                }
                fw.insert(hsh);
                int id=it->id;
                ull val=it->val;
                val=val*P+s[id][++len[id]];
                ++ans;
                S.erase(it);
                S.insert(Pr(val,id));
            }

        }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
