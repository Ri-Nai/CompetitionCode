#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e6+6;
    int n;
    int A[N];
    ll S[N],B[N];
    int rd()
    {
        int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
        while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
        return f?-t:t;
    }
    void solve()
    {
        n=rd();
        for(int i=1;i<=n;++i)
        {
            A[i]=rd();
            if(i>1)B[i-1]=A[i-1]-A[i];
        }
        --n;
        sort(B+1,B+n+1);
        reverse(B+1,B+n+1);
        for(int i=1;i<=n;++i)S[i]=S[i-1]+B[i];
        int m=rd();
        for(int op,x;m--;)
        {
            op=rd(),x=rd();
            if(op)cout<<S[n]-S[x-1]<<"\n";
        }
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
