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
    map<vector<int>,int>mp;
    bool dfs(vector<int> now)
    {
        if(now.size()==1)return 1;
        if(now.size()==2)return 0;
        int ans=0;
        for(int i=1;i<now.size();++i)
            ans^=now[i]^now[i-1]^1;
        ans^=now[0]^now.back()^1;
        return ans;
    }
    void solve()
    {
        int n=rd();
        vector<int>A(n);
        for(int i=0;i<n;++i)A[i]=rd()&1;
        puts(dfs(A)?"qcjj":"zn");
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
