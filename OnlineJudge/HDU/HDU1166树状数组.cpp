#include<cstdio>
#include<cstring>
const int maxn=5e4+5;
int n;long long C[maxn];
inline int lowb(const int&x){return x&-x;}
void Add(int x,int y)
{
	while(x<=n)C[x]+=y,x+=lowb(x);
}
long long query(int x)
{
	long long res=0;
	while(x)res+=C[x],x-=lowb(x);
	return res;
}
void solve(int id)
{
	printf("Case %d:\n",id);
	scanf("%d",&n);memset(C,0,sizeof C);
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),Add(i,x);
	while(1)
	{
		char tmp[6];scanf("%s",tmp);
		if(tmp[0]=='E')break;
		int i,j;scanf("%d%d",&i,&j);
		if(tmp[0]=='A')Add(i,j);
		if(tmp[0]=='S')Add(i,-j);
		if(tmp[0]=='Q')printf("%lld\n",query(j)-query(i-1));
	}

}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
}