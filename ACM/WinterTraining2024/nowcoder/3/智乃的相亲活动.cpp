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
    double Solve(int n,int m,vector<vector<int>> E)
    {
        double ans=0;
        vector<double>P(n+1);
        for(int i=1;i<=m;++i)
        {
            if(E[i].empty())continue;
            double ave=1./E[i].size();
            for(int v:E[i])
            {
                double p=(1-P[v])*ave;
                ans+=p;
                P[v]+=p;
            }
        }
        return ans;
    }
    void solve()
    {
        int n=rd(),m=rd(),t=rd();
        vector<vector<int>>M(n+1),W(m+1);
        while(t--)
        {
            int u=rd(),v=rd();
            M[u].push_back(v);
            W[v].push_back(u);
        }
        puts("float");
        printf("%.8lf %.8lf\n",Solve(n,m,W),Solve(m,n,M));
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
