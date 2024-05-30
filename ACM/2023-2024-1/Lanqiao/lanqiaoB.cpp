#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8;
int n;
int A[N];
namespace P40
{
    void Solve()
    {
        int cnt=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<i;++j)
            {
                int p=A[i],q=A[j];
                while(p|q)
                {
                    int x=p%10,y=q%10;
                    if(x+y>=10)
                    {
                        ++cnt;break;
                    }
                    p/=10;
                    q/=10;
                }
            }
        cout<<cnt<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>A[i];
    if(n<=2000)P40::Solve();
}
