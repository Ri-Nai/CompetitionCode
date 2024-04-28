#include<cstdio>
#include<cstring>
#define LL long long
const int pr[10][4]=
{
	{0,0,0,0},{0,0,0,0},
	{1,0,0,0},{0,1,0,0},
	{2,0,0,0},{0,0,1,0},
	{1,1,0,0},{0,0,0,1},
	{3,0,0,0},{0,2,0,0}//记录0~9内每个质因数的个数
},num[4]={2,3,5,7};//每个质因数的下标
LL dp[20][30][19][13][11];//状态 pos 2357的个数
LL L,R,ans,Pow[20],up,low;
int cnt[5];
LL dfs(int pos,LL sum)
{
	if(cnt[0]<0||cnt[1]<0||cnt[2]<0||cnt[3]<0)return 0;//无法保证上一次递归得到的cnt是否非负
	LL mn=sum*Pow[18-pos],mx=mn+Pow[18-pos]-1;//当前的前缀能得到的最大值与最小值
	if(mn>up||mx<low)return 0;//如果最大最小值不符合条件,return 0;
	if(pos==18)return !cnt[0]&&!cnt[1]&&!cnt[2]&&!cnt[3];
	bool flag=(mn>=low&&mx<=up);LL res=0;
	if(flag&&~dp[pos][cnt[0]][cnt[1]][cnt[2]][cnt[3]])//完全在范围内的可以记忆化;
		return dp[pos][cnt[0]][cnt[1]][cnt[2]][cnt[3]];
	for(int i=sum!=0;i<=9;++i)//如果是第一位,可以为0(前导0)
	{
		cnt[0]-=pr[i][0];cnt[1]-=pr[i][1];
		cnt[2]-=pr[i][2];cnt[3]-=pr[i][3];
		res+=dfs(pos+1,sum*10+i);
		cnt[0]+=pr[i][0];cnt[1]+=pr[i][1];
		cnt[2]+=pr[i][2];cnt[3]+=pr[i][3];
	}
	if(flag)dp[pos][cnt[0]][cnt[1]][cnt[2]][cnt[3]]=res;
	return res;
}
void pre(int id,LL pro)//pre函数枚举每个质因数出现的个数与乘积id-个数,pro-乘积
{
	if(1.0*pro*pro>R)return ;//double类型可存的值很大 如果超过上界直接return
	if(id==4)//如果枚举结束
	{
		low=(L-1)/pro+1,up=R/pro;//因为存的是数位的积,故数值的上下界要除去乘积
		ans+=dfs(0,0);
		return ;
	}
	pre(id+1,pro);++cnt[id];
	pre(id,pro*num[id]);--cnt[id];
	//dfs预处理
}
int main()
{
	memset(dp,-1,sizeof dp);Pow[0]=1;
	for(int i=1;i<=18;++i)Pow[i]=Pow[i-1]*10;//预处理末尾0的个数(10的幂次)
	scanf("%lld%lld",&L,&R);
	pre(0,1);printf("%lld\n",ans);
}