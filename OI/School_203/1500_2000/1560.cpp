#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
#define DOR(i,a,b) for(int i=a,i##_=b;i>=i##_;--i)
const int N=105;
int A[N],B[N],nxt[N],n;
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int find(int *arr,int x)
{
	FOR(i,1,n)if(arr[i]==x)return i;//该值在哪个位置
}
int dis(int *arr,int u,int v)
{
	return (find(arr,u)-find(arr,v)+n)%n;//两点的距离
}
void jump(int x)
{
	printf("%d\n",x);int p=find(A,x);
	while(x--)swap(A[p],A[nxt[p]]),p=nxt[p];//跳跃一步等于直接交换
}
int main()
{
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",&A[i]),nxt[i]=i+1;
	FOR(i,1,n)scanf("%d",&B[i]);
	nxt[0]=1;nxt[n]=1;
	DOR(i,n-2,1)
	{
		int now=nxt[find(B,i)],Gcd;
		while(B[now]<=i)now=nxt[now];
		now=B[now];Gcd=gcd(i,n-1);//跳多少次
		while(1)
		{
			int Dis=dis(A,now,i)-1;//两点距离-1
			if(Dis%Gcd==0)break;//原地
			while(dis(A,i,1)!=1)jump(1);
			jump(i);
		}
		while(dis(A,now,i)!=1)jump(i);
	}
	while(dis(A,1,n)!=dis(B,1,n))jump(n);
}