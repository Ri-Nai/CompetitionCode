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
		for(int j=m;j;--j)//��ֹ������һά�� 
		{
			bool p=A[i]==B[j];
			int bg=min(j,K);
			for(int k=bg;k;--k)//�̳�ǰ��Ĵ��Ĵ���
				if(p)f[j][k]=(f[j][k]+(dp[j][k]=(dp[j-1][k]+f[j-1][k-1])%mod))%mod;
				else dp[j][k]=0;//��һάû�д� ֻ�ܽ���һ���µĴ� 
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


�Ҿ���O(nm^2) ��ǿ�ܳ� ͦ/se��

����dpͦ�����
Ҫô����һ���µĴ�,Ҫô�ͼ̳�ǰ��Ĵ�
�µĴ�����������ǰ��Ĵ𰸺� 

dp[N][M][M]��ʾ��Ai���ַ�,��Bj���ַ��͵�k����
������Ŀ���ڴ�,���ù���ͦ��д��,Ҳû��������Ǹ�����n^2��ʼ�� 

*/
