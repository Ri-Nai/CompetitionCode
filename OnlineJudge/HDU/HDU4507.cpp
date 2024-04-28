#include<cstdio>
#define LL long long
const int HD=1e9+7;//膜HD
struct node
{
	LL cnt,sum,sqsum;
	node(){cnt=sum=sqsum=0;}
	node(LL _cnt,LL _sum,LL _sqsum):cnt(_cnt),sum(_sum),sqsum(_sqsum){}//构造函数定义
	void Add(LL a,node nxt)
	{
		LL num=nxt.cnt%HD;
		(cnt+=num)%=HD;
		(sum+=(nxt.sum+num*a%HD)%HD)%=HD;
		(sqsum+=(nxt.sqsum+2*a%HD*nxt.sum%HD+num*a%HD*a%HD)%HD)%=HD;
		/*
		无取模精简版
		cnt+=num;
		sum+=nxt.sum+num*a;
		sqsum+=nxt.sqsum+2*a*nxt.sum+num*a*a;
		*/
	}
}dp[25][15][15];
LL fact[25],x,y,A[25];
bool mark[25][15][15];//其实也可以在构造函数内定义初始值为-1达到标记的效果
void init()//填充10的幂次
{
	fact[1]=1;
	for(int i=2;i<=19;++i)fact[i]=fact[i-1]*10%HD;
}
node dfs(int pos,int sum,int rest,bool lmt)
{
	if(!pos)
	{
		if(rest&&sum)return node(1,0,0);
		return node();
	}
	if(!lmt&&mark[pos][sum][rest])return dp[pos][sum][rest];
	int Up=lmt?A[pos]:9;node res=node();
	for(int i=0;i<=Up;++i)
		if(i!=7)res.Add(i*fact[pos],dfs(pos-1,(sum+i)%7,(rest*10+i)%7,lmt&&i==Up));
	if(!lmt)mark[pos][sum][rest]=1,dp[pos][sum][rest]=res;
	return res;
}
LL solve(LL num)
{
	int len=0;
	while(num)A[++len]=num%10,num/=10;
	return dfs(len,0,0,1).sqsum;
}
int main()
{
	init();int T;scanf("%d",&T);
	while(T--)
		scanf("%lld%lld",&x,&y),
		printf("%lld\n",(solve(y)-solve(x-1)+HD)%HD);//相减之后可能会小于0故加上模数
}