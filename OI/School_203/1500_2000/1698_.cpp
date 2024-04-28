#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5,mod=1e9+7;
int m,n;
char A[N],B[N];
void Add(int x,int y)
{
	x+=y;x<0&&(x+=mod);
	x>=mod&&(x-=mod);
}
struct node
{
	int ans,num;
	node(){ans=0;num=1;}
	node(int _,int __){ans=_;num=__;}
	void Plus(const node &_,int dif)
	{
		Add(ans,_.ans);
		Add(num,_.num);
		Add(ans,1ll*_.num*dif%mod)
	}
}dp[4][4][N];
void read(char *s,int &len)
{
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;++i)
		s[i]=
}
int main()
{
}