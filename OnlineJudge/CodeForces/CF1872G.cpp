#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=2e5+5;
    int A[M],Sum[M],B[M];
    void Solve()
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>A[i],Sum[i]=Sum[i-1]+A[i];
        int l=1,r=n;
        while(l<=n and A[l]==1)++l;
        while(r>=1 and A[r]==1)--r;
        if(l>n)return cout<<"1 1\n",void();
        long long res=1;
        int cnt=0;
        for(int i=l;i<=r;++i)
        {
            res*=A[i];
            if(A[i]!=1)B[++cnt]=i;
            if(res>1e9)return cout<<l<<' '<<r<<'\n',void();
        }
        int mx=0;
        int ml=1,mr=1;
        for(int i=1;i<=cnt;++i)
        {
            for(int j=i;j<=cnt;++j)
            {
                int res=1;
                for(int k=i;k<=j;++k)
                    res*=A[B[k]];
                res-=Sum[B[j]]-Sum[B[i]-1];
                if(res>mx)mx=res,ml=B[i],mr=B[j];
            }
        }
        cout<<ml<<' '<<mr<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)T::Solve();
}

