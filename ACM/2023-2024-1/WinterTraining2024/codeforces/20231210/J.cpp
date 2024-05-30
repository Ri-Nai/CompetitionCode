#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char A[N],B[N];
int n;
void Solve()
{
    cin>>n;
    cin>>A+1;
    cin>>B+1;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int x=abs(A[i]-B[i]);
        ans+=min(x,26-x);
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    Solve();
}
