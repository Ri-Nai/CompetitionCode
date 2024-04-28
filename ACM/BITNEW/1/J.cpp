#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=1e6+5;
    char s[M];
    int l1,l2,A[M],B[M],sum[M];
    bool cmp(int p,int l,char *s,char *t)
    {
        for(int i=0;i<l;++i)
            if(s[i+p]!=t[i])return 0;
        return 1;
    }

    void solve()
    {
        cin>>s+1;
        int n=strlen(s+1);
        char s1[6]={"skql"};
        char s2[6]={"ao"};
        for(int i=1;i<=n;++i)
        {
            if(i+3<=n)
                if(cmp(i,4,s,s1))
                    A[++l1]=i+4;
            if(i+1<=n)
                if(cmp(i,2,s,s2))
                    B[++l2]=i-1;
            sum[i]=sum[i-1]+(s[i]=='i');
        }
        int ans=7;
        for(int i=1,j=1;i<=l2;++i)
        {
            // cout<<A[j]<<'\n';
            while(j+1<=l1 and A[j+1]<=B[i])++j;
            int l=A[j],r=B[i];
            if(sum[r]-sum[l-1]==r-l+1)
                ans=max(ans,r-l+1+6);
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
