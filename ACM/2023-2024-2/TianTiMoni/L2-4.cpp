#include<bits/stdc++.h>
using namespace std;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(res<<1)+(res<<3)+(c^48),c=getchar();
    return res*f;
}
namespace T
{
    int n,m;
    const int N=5e5+5,mod=998244353;
    char s[N];
    void Solve()
    {
        cin>>n>>m;
        cin>>s+1;
        for(register int i=1;i<=m;++i)
        {
            int op=rd(),l=rd(),r=rd();
            if(op==1)
            {
                char c=getchar();
                for(register int i=l;i<=r;++i)s[i]=c;
            }
            else
            {
                vector<int>has(5);
                for(register int i=l;i<=r;++i)
                {
                    if(s[i]=='(')++has[0];
                    if(s[i]=='0')has[1]=(has[1]+has[0])%mod,has[3]=(has[3]+has[2])%mod;
                    if(s[i]=='w')has[2]=(has[2]+has[1])%mod;
                    if(s[i]==')')has[4]=(has[3]+has[4])%mod;
                }
                printf("%d\n",has[4]);
            }
        }
    }
}
int main()
{
    T::Solve();
}
