#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,A[N],len[N],in[N],num,nnm;
char s[N][N],ans[N];
bool flag,mark[N];
int head[N],to[N*N],nxt[N*N],tot;
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
    if(len[u]>len[v])flag=1;
}
queue<int>Q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%s",s[i]+1);
    	len[i]=strlen(s[i]+1);
    	for(int j=1;j<=len[i];++j)
    		if(!mark[s[i][j]-'a'])++nnm,mark[s[i][j]-'a']=1;
    }
    for(int i=1;i<n;++i)
    	for(int j=i+1;j<=n;++j)
			compare(i,j);
    if(flag)return puts("!"),0;
    for(int i=0;i<26;++i)
        if(mark[i]&&!in[i])Q.push(i);
    if(Q.empty())return puts("!"),0;
    while(!Q.empty())
    {
	    if(Q.size()>1)
		{
			puts("?");
			return 0;
		}
        int u=Q.front();Q.pop();
        ans[++num]='a'+u;int kk=0;
        for(int i=head[u];i;i=nxt[i])
            if(--in[to[i]]==0)Q.push(to[i]);
    }
    if(num!=nnm)puts("!");
    else for(int i=1;i<=num;++i)
        	putchar(ans[i]);
}