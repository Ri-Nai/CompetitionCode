#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int A[N],B[N];
int n;
void Solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>A[i];
    for(int i=1;i<=n;++i)cin>>B[i];
    sort(A+1,A+n+1);
    sort(B+1,B+n+1);
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(A[i]>B[j])++cnt;
            if(A[i]<B[j])--cnt;
        }
    }
    if(cnt>0)cout<<"first\n";
    if(cnt<0)cout<<"second\n";
    if(cnt==0)cout<<"tie\n";
}
int main()
{
    ios::sync_with_stdio(0);
    Solve();
}
