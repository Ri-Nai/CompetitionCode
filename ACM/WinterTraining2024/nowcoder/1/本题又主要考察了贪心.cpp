#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n=rd(),m=rd();
        vector<int>A(n+1);
        for(int i=1;i<=n;++i)
            A[i]=rd();
        vector<int>u(m+1),v(m+1);
        for(int i=1;i<=m;++i)u[i]=rd(),v[i]=rd();
        int p=pow(3,m);
        int ans=n;
        for(int i=0;i<p;++i)
        {
            vector<int>B=A;
            int x=i;
            for(int j=1;j<=m;++j)
            {
                int k=x%3;
                if(k==0)++B[u[j]],++B[v[j]];
                if(k==1)B[u[j]]+=3;
                if(k==2)B[v[j]]+=3;
                x/=3;
            }
            vector<int>C=B;
            // cout<<"AAA\n";
            sort(C.begin()+1,C.end());
            int now=upper_bound(C.begin()+1,C.end(),B[1])-C.begin();//大于他的如果是n+1那他就是第一名
            ans=min(n+2-now,ans);
        }
        cout<<ans<<'\n';
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
