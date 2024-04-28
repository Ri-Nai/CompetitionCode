#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1e5+5;
int n,m,tot,trie[32*maxn][2];
LL val[32*maxn];
void updata(LL x)
{
    int rt=0;
    for(int i=32;~i;--i)
    {
        int id=(x>>i)&1;
        if(!trie[rt][id]) trie[rt][id]=++tot;
        rt=trie[rt][id];
    }
    val[rt]=x;
}
LL query(LL x)
{
    int rt=0;
    for(int i=32;~i;--i)
    {
        int id=(x>>i)&1;
        if(trie[rt][id^1])rt=trie[rt][id^1];
        else rt=trie[rt][id];
    }
    return val[rt];
}
void solve()
{
    scanf("%d%d",&n,&m);LL x;
    memset(trie,0,sizeof trie);
    for(int i=1;i<=n;++i)
        scanf("%lld",&x),updata(x);
    while(m--)
        scanf("%lld",&x),
        printf("%lld\n",query(x));
}
int main()
{
    int T;scanf("%d",&T);
    for(int cas=1;cas<=T;++cas)
        printf("Case #%d:\n",cas),solve();
}