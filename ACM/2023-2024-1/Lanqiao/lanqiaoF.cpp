#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8,mod=998244353;
typedef long long ll;
int n,m,A[N],B[N];
struct Poi
{
    int p,x;
    bool operator <(const Poi &_)const
    {
        if(x==_.x)return p<_.p;
        return x<_.x;
    }
}tmp[N];
multiset<Poi>S;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>A[i];
    for(int i=1;i<=n;++i)cin>>B[i];
    sort(B+1,B+n+1);
    for(int i=1;i<=n;++i)S.insert((Poi){i,A[i]});
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        int p,x;
        cin>>p>>x;
        S.erase((Poi){p,A[p]});
        S.insert((Poi){p,A[p]=x});
        // multiset<Poi>M=S;
        int cnt=0;
        for(int j=1;j<=n;++j)
        {
            if(S.begin()->x<B[j])
            {
                tmp[++cnt]=*S.begin();
                S.erase(S.begin());
            }
        }
        for(int i=1;i<=cnt;++i)S.insert(tmp[i]);
        cout<<cnt<<'\n';
    }
}
