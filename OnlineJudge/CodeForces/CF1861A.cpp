#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int pr[N],p[N],len;
void init()
{
    for(int i=2;i<N;++i)
        if(!p[i])
        {
            pr[++len]=i;
            for(int j=i+i;j<N;j+=i)
                p[j]=1;
        }
    // for(int i=1;i<=len;++i)
    //     printf("%d ",pr[i]);
}
namespace T
{
    char s[11];
    int flag,ans;
    bool check(int res)
    {
        if(res<10)return 0;
        for(int i=1;1ll*pr[i]*pr[i]<=res;++i)
            if(res%pr[i]==0)return 0;
        return 1;
    }
    void dfs(int now,int res)
    {
        // printf("%d\n",now);
        if(now==11)
        {
            if(check(res))flag=1,ans=res;
            return;
        }
        if(flag)return;
        dfs(now+1,res);
        dfs(now+1,res*10+s[now]-48);
    }
    void solve()
    {
        scanf("%s",s+1);
        ans=-1,flag=0;
        dfs(1,0);
        printf("%d\n",ans);
    }
}
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)T::solve();
}
