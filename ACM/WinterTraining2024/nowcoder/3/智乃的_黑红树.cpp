#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    const int N=2e5+5;
    int ls[N],rs[N];
    void Build(int rt,int a,int b)
    {
        int p=rt;
        for(int i=rt;i<rt+b;++i)
            ls[i]=++p;
        int q=p+1;
        for(int i=rt;i<rt+b;++i)
            rs[i]=++p;
        a-=b+1;
        for(int i=q;a;a-=2,i+=2)
            ls[i]=++p,rs[i]=++p;
    }
    void solve()
    {
        int a=rd(),b=rd(),n=a+b;
        if(!(a&1) or (b&1))End("No");
        if(b>a*2 or a>b*2+1)End("No");
        for(int i=1;i<=n;++i)ls[i]=rs[i]=-1;
        if(b>a)
        {
            ls[1]=2;
            rs[1]=3;
            Build(3,b-1,a-1);
        }
        else Build(1,a,b);
        puts("Yes");
        for(int i=1;i<=n;++i)
            cout<<ls[i]<<' '<<rs[i]<<'\n';

    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
