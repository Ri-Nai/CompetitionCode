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
    void solve()
    {
        // int n=rd();
        int n;cin>>n;
        vector<int>mp(256);
        vector<int>mark(10);
        vector<int>res(7);
        map<string,int>vis;
        string x,y;
        cin>>x>>y;
        for(int i='a';i<='d';++i)mp[i]=i-'a'+1;
        mp['_']=5;
        int ans=0;
        auto trans=[&](string s)
        {
            int res=0;
            for(int i=0;i<n;++i)
                res=res*10+s[i]-48;
            return res;
        };
        auto check=[&]()->bool
        {
            string now;
            for(int i=0;i<n;++i)
                if(mp[x[i]])now+=res[mp[x[i]]];
                else now+=x[i];
            if(vis[now])return 0;
            vis[now]=1;
            if(n>1 and now[0]=='0')return 0;
            if(now<=y and trans(now)%8==0)return 1;
            return 0;
        };
        auto dfs=[&](auto self,int x)->void
        {
            if(x==6){ans+=check();return ;}
            for(int i='0';i<='9';++i)
            {
                if(x!=5 and mark[i^48])
                    continue;
                ++mark[i^48];
                res[x]=i;
                self(self,x+1);
                --mark[i^48];
            }
        };
        dfs(dfs,1);
        cout<<ans<<'\n';
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
