#include<cmath>
#include<cstdio>
#include<cstring>
const int maxn=2e4+56;
int cnt[maxn],ans[maxn],tot,len,pr[maxn][10],res[maxn];
bool mark[maxn];char s[maxn];
void init()
{
	mark[0]=mark[1]=1;
	for(int i=2;i<=len;++i)
		if(!mark[i])for(int j=i;j<=len;j+=i)
			mark[j]=1,pr[j][++pr[j][0]]=i;
}
void Time(int x)
{
	for(int i=0;i<=tot;++i)ans[i]*=x;//,printf("%d\n",ans[i]);;
	for(int i=0;i<=tot;++i)ans[i+1]+=ans[i]/10,ans[i]%=10;
	while(ans[tot+1]>0)++tot,ans[tot+1]+=ans[tot]/10,ans[tot]%=10;
}
void resolve(int x,int mark)
{
    for(int i=1;i<=x;++i)
    {
        int tmp=i;
        for(int j=1;j<=pr[i][0];++j)
            while(tmp%pr[i][j]==0)
                res[pr[i][j]]+=mark,
                tmp/=pr[i][j];
    }
}

void solve()
{
	len>>=1;init();/*printf("%d",ans[0]);*/
	resolve(len,1);
	for(int i='A';i<='Z';++i)
		resolve(cnt[i],-1);
	for(int i=1;i<=20000;++i)
        while(res[i])Time(i),--res[i];
        //C(len,cnt[i]),len-=cnt[i];
    //printf("%d",tot);
    for(int i=tot;~i;--i)
    	printf("%d",ans[i]);
}
void in_put()
{
	scanf("%s",s+1);len=strlen(s+1);
    int flag=0;ans[0]=1;
	for(int i=1;i<=len;++i)++cnt[s[i]];
    for(int i='A';i<='Z';++i)flag+=cnt[i]&1,cnt[i]>>=1;
    if(flag!=(len&1))puts("0");
    else solve();
}
int main()
{
	in_put();
}