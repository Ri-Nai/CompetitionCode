#include<bits/stdc++.h>
using namespace std;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(res<<1)+(res<<3)+(c^48),c=getchar();
    return res*f;
}
namespace T
{
    bool check(int x)
    {
        if(x==1)return 0;
        for(int i=2;i<x;++i)
            if(x%i==0)return 0;
        return 1;
    }
    void Solve()
    {
        map<int,long long>A,B,ans1,ans2;
        int n;cin>>n;
        if(n==0)A[0]=0,ans1[0]=ans2[0]=0;
        for(int i=1;i<=n;++i)
        {
            int a,b;
            cin>>a>>b;
            A[b]=a;
            ans2[b]+=a;
        }
        cin>>n;
        if(n==0)B[0]=0,ans1[0]=ans2[0]=0;
        for(int i=1;i<=n;++i)
        {
            int a,b;
            cin>>a>>b;
            B[b]=a;
            ans2[b]+=a;
        }
        for(auto [x,y]:A)
            for(auto [u,v]:B)
                ans1[x+u]+=y*v;
        vector<pair<int,long long>>ans1v,ans2v;
        for(auto [x,y]:ans1)if(y)ans1v.push_back({x,y});
        for(auto [x,y]:ans2)if(y)ans2v.push_back({x,y});
        if(ans1v.empty())ans1v.push_back({0,0});
        if(ans2v.empty())ans2v.push_back({0,0});
        reverse(ans1v.begin(),ans1v.end());
        reverse(ans2v.begin(),ans2v.end());
        for(int i=0;i<ans1v.size();++i)
        {
            auto [x,y]=ans1v[i];
            cout<<y<<' '<<x<<" \n"[i==ans1v.size()-1];
        }
        for(int i=0;i<ans2v.size();++i)
        {
            auto [x,y]=ans2v[i];
            cout<<y<<' '<<x<<" \n"[i==ans2v.size()-1];
        }
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    T::Solve();
}
