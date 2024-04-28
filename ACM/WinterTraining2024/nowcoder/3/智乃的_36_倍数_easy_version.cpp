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
    int check(string a,string b)
    {
        string t=a+b;
        int now=0;
        for(int j=0;j<t.size();++j)
        {
            now=now*10+t[j]-48;
        }
        return now%36==0;
    }
    void solve()
    {
        int n=rd(),ans=0;
        vector<string>A(n);
        for(int i=0;i<n;++i)cin>>A[i];
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(i!=j)ans+=check(A[i],A[j]);
        cout<<ans<<'\n';
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
