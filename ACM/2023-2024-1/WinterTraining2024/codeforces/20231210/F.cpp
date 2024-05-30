#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int A[N],B[N];
int n;
void Solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>A[i];
    sort(A+1,A+n+1);
    cout<<(0ll+A[1]+A[2])<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    Solve();
}
