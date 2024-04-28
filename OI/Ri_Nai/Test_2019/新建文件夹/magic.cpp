#include<cstdio>
#define F
const int maxn=1.5e4+56,maxm=4e4+5;
int cnt[maxn],n,m,x[maxn],A[maxn],B[maxn],C[maxn],D[maxn];
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&x[i]),
		++cnt[x[i]];
	for(int e=1,sum=0;e*9<n;++e)
	{
		sum=0;
		for(int d=9*e+2;d<=n;++d)
		{
			int c=d-e,
			a=d-9*e-1,b=a+2*e;//最小的g为1 求出最小的ab 
			sum+=cnt[a]*cnt[b];
			//printf("%d\n",sum);
			C[c]+=sum*cnt[d];//C的情况必须要D 
			D[d]+=sum*cnt[c];
		}
		sum=0;
		for(int a=n-9*e-1;a;--a)
		{
			int b=a+2*e,
			c=b+6*e+1,d=c+e;
			sum+=cnt[c]*cnt[d];
		//	printf("%d\n",sum);
			A[a]+=sum*cnt[b];
			B[b]+=sum*cnt[a];
		}
	}
	for(int i=1;i<=m;++i)
		printf("%d %d %d %d\n",A[x[i]],B[x[i]],C[x[i]],D[x[i]]);
}
int main()
{
	#ifndef F
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
/*
30 8
1
24
7
28
5
29
26
24
15 15
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
a<b<c<d
b-a=2(d-c)<(c-b)/3;
3b-3a=6d-6c<(c-b)
d-c=e
f=2e
6e<c-b
6e+g=c-b
a~b 2e b~c 6e+g c~d e
2e 6e+9 e
d-a=9e+c 
a>=1 d<=n
(n-1)/9>=e
e<=(n-1)/9
9e+1<=n;
9e<n
枚举 e可以枚举D 枚举D可以求出C 根据范围
可以求出 a、b 求出CD的值
同理枚举a、b求出ab的值 

当ax<ay&&bx<by时 CD不变 若ayby都可以和CD组cp
那必定可以
只需将和不断累加

当cx>cy&&dx>dy时 AB不变  同上  

所以不必将求出来的范围枚举一遍

只需求出最大的AB //从大到小 
最小的CD //从小到大 
不断累加即可
 
g>=1

D>=A+g+9e

D>=9e+2

D<=n;
A+g+9e<=n
A<=n-9e-1
 
b-a<(c-b)/
*/
