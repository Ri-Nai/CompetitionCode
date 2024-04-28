#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1005,M=205,mod=1e9+7; 
int n,m,K,f[M][M],dp[M][M];
char A[N],B[N];
int main()
{
//	FILE("substring");
	scanf("%d%d%d",&n,&m,&K);
	scanf("%s%s",A+1,B+1);
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=m;j;--j)//防止更新这一维的 
		{
			bool p=A[i]==B[j];
			int bg=min(j,K);
			for(int k=bg;k;--k)//继承前面的串的答案数
				if(p)f[j][k]=(f[j][k]+(dp[j][k]=(dp[j-1][k]+f[j-1][k-1])%mod))%mod;
				else dp[j][k]=0;//这一维没有答案 只能建立一个新的串 
		}
	printf("%d\n",f[m][K]);
	FCLS();
}
/*
6 3 1
aabaab aab

6 3 2
aabaab aab


6 3 3
aabaab aab


我觉得O(nm^2) 勉强能冲 挺/se的

计数dp挺好想的
要么建立一个新的串,要么就继承前面的答案
新的串的种数就是前面的答案和 

dp[N][M][M]表示第Ai个字符,第Bj个字符和第k个串
阴间题目爆内存,还好滚动挺好写的,也没有昨天的那个阴间n^2初始化 

*/
