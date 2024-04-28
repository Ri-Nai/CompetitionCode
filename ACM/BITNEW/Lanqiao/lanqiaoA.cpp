#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+8;
int n;
ll m,k,b,h1,h2;
int H[N];
ll ans=0;
int check(int h)
{
    if(h>=h1 and h>=h2)
        return m;
    if(h<h1 and h<h2)
        return 0;
    return (h-b)/k;

}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m>>k>>b;
    for(int i=1;i<=n;++i)
        cin>>H[i];
    if(k<0)
    {
        b=b+k*(m+1);
        k=-k;
    }
    // cout<<k<<' '<<b<<'\n';
    h1=k+b,h2=m*k+b;
    for(int i=1;i<=n;++i)
        ans+=check(H[i]);
    cout<<ans<<'\n';
}
//k*i+1
