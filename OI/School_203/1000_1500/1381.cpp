#include<cstdio>
#include<cstring>
const int maxn=100005;
int fa[maxn],L,R,p,k=0;
bool mark[maxn];
void init()
{
    for(int i=2;i<=R;++i)
        if(!mark[i])
            for(int j=i+i;j<=R;j+=i)
                mark[j]=1;
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
    scanf("%d%d%d",&L,&R,&p);
    init();
    for(int i=L;i<=R;++i)fa[i]=i;
    for(int i=p;i<=R;++i)
        if(!mark[i])
    	    for(int j=L/i*i;j<=R;j+=i)
    	    {
	            if(j<L)continue;
	            if(L%i==0)fa[find(j)]=find(L);
	            else fa[find(j)]=find((L/i+1)*i);
	        }
    int ans=0;
    for(int i=L;i<=R;++i)if(fa[i]==i)++ans;
    printf("%d\n",ans);
}