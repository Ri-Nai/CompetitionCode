#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,A[N],len[N],in[N],num;
char s[N][N],ans[N];
bool flag;
int head[N],to[N],nxt[N],tot;
void Add(int u,int v)
{
    nxt[++tot]=head[u];
    to[tot]=v;head[u]=tot;
    ++in[v];
}
void compare(int u,int v)
{
    for(int i=1;i<=len[u]&&i<=len[v];++i)
        if(s[u][i]!=s[v][i])
            return Add(s[u][i]-'a',s[v][i]-'a');
    if(len[u]>=len[v])flag=1;
}
queue<int>Q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%s",s[i]+1),
        len[i]=strlen(s[i]+1);
    for(int i=1;i<=n;++i)
        scanf("%d",&A[i]);
    for(int i=1;i<n;++i)
 		compare(A[i],A[i+1]);
    if(flag)
    {
        puts("NE");
        return 0;
    }
    for(int i=0;i<26;++i)
        if(!in[i])Q.push(i);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        ans[u]=(num++)+'a';
        for(int i=head[u];i;i=nxt[i])
            if(--in[to[i]]==0)Q.push(to[i]);
    }
    if(num<26)puts("NE");
    else
    {
        puts("DA");
        for(int i=0;i<26;++i)
            putchar(ans[i]);
    }
}