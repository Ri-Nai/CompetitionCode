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
        vector<int>Sum(n+1),A(n+1);
        for(int i=1;i<=n;++i)A[i]=rd();
        for(int i=1;i<=n;++i)Sum[i]=Sum[i-1]+A[i];
        for(int i=1;i<=n;++i)
        {
            int l=1,r=i-1,res1=-1;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(Sum[i-1]-Sum[mid-1]>A[i])
                    res1=i-mid,l=mid+1;
                else r=mid-1;
            }
            l=i+1,r=n;
            int res2=-1;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(Sum[mid]-Sum[i]>A[i])
                    res2=mid-i,r=mid-1;
                else l=mid+1;
            }
            if(res1==-1)cout<<res2;
            else if(res2==-1)cout<<res1;
            else cout<<min(res1,res2);
            cout<<" \n"[i==n];
        }
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
