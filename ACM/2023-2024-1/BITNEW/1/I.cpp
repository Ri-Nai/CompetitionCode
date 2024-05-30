#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=1e5+5;
    int n,k,A[N],Sum[N];
    int Search(int p)
    {
        int l=p,r=n,res=-1;
        if(Sum[r]-Sum[l-1]<k)return -1;
        while(l<=r)
        {
            int mid=l+r>>1;
            int now=Sum[mid]-Sum[p-1];
            if(now>=k)
            {
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
    void solve()
    {
        cin>>n>>k;
        for(int i=1;i<=n;++i)
            cin>>A[i],Sum[i]=Sum[i-1]+A[i];
        int ans=1e9+7;
        for(int i=1;i<=n;++i)
        {
            if(A[i])
            {
                int t=Search(i);
                if(~t)ans=min(ans,t-i+1);
            }
        }
        cout<<(ans==1e9+7?-1:ans)<<'\n';

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
