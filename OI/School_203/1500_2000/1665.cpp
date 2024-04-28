#include<bits/stdc++.h>
using namespace std;
typedef long double DB;
const int N=1e5+5,M=1005;
struct BIT
{
	DB C[M];
	void Add(int x,DB y,int z){while(x<M)C[x]+=y*z,x+=x&-x;}
	DB Sum(int x){DB res=0;while(x)res+=C[x],x^=x&-x;return res;}
}B0,B1,B2;
int A[N],n,Q;char s[20];
int rd()
{
	int t=0,c;
	do c=getchar();while(!isdigit(c));
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
void Insert(int u,int v,int w)
{
	if(u>v)swap(u,v);

	B0.Add(v+1,(-u-v)/2.0,w);
	B1.Add(v+1,1.0,w);

	if(v-u==0)return ;

	DB d=(v-u)*2;
	B0.Add(u,u*u/d,w);//a^2
	B0.Add(v+1,u*u/d,-w);

	B1.Add(u,u*2/d,-w);//-2xa
	B1.Add(v+1,u*2/d,w);

	B2.Add(u,1/d,w);
	B2.Add(v+1,1/d,-w);//x^2
}
int main()
{
	n=rd();Q=rd();
	for(int i=1;i<=n;++i)A[i]=rd()+1;
	for(int i=1;i<n;++i)Insert(A[i],A[i+1],1);
	for(int x;Q--;)
	{
		scanf("%s",s);
		if(s[0]=='Q')x=rd()+1,
			printf("%.1Lf\n",x*x*B2.Sum(x)+x*B1.Sum(x)+B0.Sum(x));
		else
		{
			x=rd()+1;
			if(x>1)Insert(A[x],A[x-1],-1);
			if(x<n)Insert(A[x],A[x+1],-1);
			A[x]=rd()+1;
			if(x>1)Insert(A[x],A[x-1],1);
			if(x<n)Insert(A[x],A[x+1],1);
		}
	}
}
/*
S_x=((x-a)*(x-a))/(2*(b-a))
-> =(x*x-2*a*x+a*a)/(2*(b-a))//对于三角形的面积
矩形的面积:1*x
下方梯形的面积(b+a)*1/2;
*/