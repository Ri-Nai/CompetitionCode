#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
const int M=1e4+5;
int n;
int A[M],L[M],R[M];
void del(int x,int &lst)
{
    L[R[x]]=L[x];
    R[L[x]]=R[x];
    cout<<x<<' '<<A[x]<<'\n';
    lst=x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    // cout<<"AAA"<<'\n';
    for(int i=1;i<=n;++i)
        cin>>A[i];
    for(int i=1;i<=n;++i)
        L[i]=i-1,R[i]=i+1;
    R[0]=1,L[n+1]=n;
    int lst=-1;
    for(int i=1;i<=n;++i)
        if(A[i]==1)del(i,lst);
    for(int k=1;k<n;++k)
    {
        int mn=1e9,p=-1;
        // cout<<k<<'\n';
        for(int i=R[0];i!=n+1;i=R[i])
        {
            // cout<<i<<' '<<R[i]<<'\n';
            int x=abs(i-lst)+abs(A[i]-A[lst]);
            if(x<mn)mn=x,p=i;
        }
        del(p,lst);
    }
}
