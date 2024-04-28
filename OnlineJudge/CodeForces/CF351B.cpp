#include<cstdio>
const int maxn=3005;
int n,C[maxn],ans;
void Add(int x){while(x<=n)++C[x],x+=x&-x;}
int sum(int x){int res=0;while(x)res+=C[x],x^=x&-x;return res;}
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),Add(x),ans+=i-sum(x);
    printf("%d.0000000\n",(ans<<1)-(ans&1));
}