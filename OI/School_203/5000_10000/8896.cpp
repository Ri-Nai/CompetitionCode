#include<bits/stdc++.h>
using namespace std;
const int maxp=6e5+5;
int n,trie[maxp][10],cnt[maxp],tot;
vector<int>E[maxp];
void insert(char *s,int len,int x,int y)
{
    int now=0;
    for(int i=0;i<len;++i)
    {
        int id=s[i]-'a';
        if(!trie[now][id])trie[now][id]=++tot;
        now=trie[now][id];
        cnt[now]+=x;
        if(cnt[now]>E[now].size())
            E[now].push_back(y);
    }
}
int find(char *s,int len)
{
    int now=0;
    for(int i=0;i<len;++i)
    {
        int id=s[i]-'a';
        if(!trie[now][id])return -1;
        now=trie[now][id];
    }
    return now;
}
int main()
{
    scanf("%d",&n);int ans=0;
    char tmp[65];
    for(int i=1,a,b,c,k;i<=n;++i)
    {
        scanf("%d%s",&k,tmp);
        if(k==1||k==2)
            insert(tmp,strlen(tmp),k==1?1:-1,i);
        else
        {
            scanf("%d%d%d",&a,&b,&c);
            k=(1ll*a*(long long)abs(ans)+b)%c;
            a=find(tmp,strlen(tmp));
            if(a==-1)printf("%d\n",ans=-1);
            else
            {
                if(k>E[a].size())printf("%d\n",ans=-1);
                else printf("%d\n",ans=E[a][k]);
            }
        }
    }
}