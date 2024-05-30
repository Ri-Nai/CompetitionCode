#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8,mod=998244353;
typedef long long ll;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=m;++i)
    {
        int now=1;
        if(n<=2)cout<<i<<" ";
        else cout<<now+4<<' ';
        now*=3;
    }
}
