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
        int n=rd(),x=rd(),y=rd();
        vector<int>A(n+1);
        for(int i=1;i<=n;++i)A[i]=rd();
        if(y<x)swap(x,y);
        auto check=[&](int p)
        {
            set<int>S;
            S.insert(x);
            S.insert(y);
            for(int i=1;i<=n;++i)
            {
                int l=*S.begin();
                int r=*S.rbegin();
                if(A[i]>l and A[i]<r)S.insert(A[i]);
                else
                {
                    if(A[i]>r)
                    {
                        if(A[i]-r>p)return 0;
                        while(!S.empty() and *S.begin()<A[i]-p)
                            S.erase(S.begin());
                        S.insert(A[i]);
                    }
                    else
                    {
                        if(l-A[i]>p)return 0;
                        while(!S.empty() and *S.rbegin()>A[i]+p)
                            S.erase(*S.rbegin());
                        S.insert(A[i]);
                    }
                }
            }
            return 1;
        };
        int l=y-x,r=1e9,res=1e9;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(check(mid))res=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<res<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
