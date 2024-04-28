#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
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
        int n=rd();
        vector<int>A;
        for(int i=1;i<=n;++i)A.push_back(rd());
        int last=-1,y=-1;
        vector<int>res;
        for(int i=0;i<n;++i)
        {
            int x=A[i];
            if(y==-1)y=x;
            if(x!=y)res.push_back(i-1-last),last=i;
        }
        res.push_back(n-1-last);
        sort(res.begin(),res.end());
        if(res.size()==1)cout<<"-1\n";
        else printf("%d\n",res[0]);
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
