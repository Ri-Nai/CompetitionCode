#include<bits/stdc++.h>
typedef unsigned uint;
using namespace std;
const int maxn=1e5+5;
int W,B[maxn],D[maxn],n,m,k,len1,len2;
uint C[maxn][15],ans,cntx[maxn],cnty[maxn],num[maxn];
int read()
{
	int t=0,c;
	do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
struct BIT
{
	uint C[maxn];
	BIT(){memset(C,0,sizeof C);}
	void Add(int x,int y){while(x<=len1)C[x]+=y,x+=x&-x;}
	uint Sum(int x){uint res=0;while(x)res+=C[x],x-=x&-x;return res;}
}T;
struct Tree//常青树,不是数据结构
{
	int x,y;
	bool operator<(Tree _)const{return y==_.y?x<_.x:y<_.y;}
}A[maxn];
void Get_C()
{
	C[0][0]=1;
	for(int i=1;i<=W;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=min(i,k);++j)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}
void pre()
{
	n=read();m=read();W=read();
	for(int i=1;i<=W;++i)
		A[i].x=read(),A[i].y=read(),
		B[i]=A[i].x,D[i]=A[i].y;
	k=read();Get_C();
	sort(B+1,B+W+1);len1=unique(B+1,B+W+1)-B-1;
	sort(D+1,D+W+1);len2=unique(D+1,D+W+1)-D-1;
	sort(A+1,A+W+1);
	for(int i=1;i<=W;++i)
		A[i].x=lower_bound(B+1,B+len1+1,A[i].x)-B,
		A[i].y=lower_bound(D+1,D+len2+1,A[i].y)-D,
		++cnty[A[i].x],++cntx[A[i].y];
}
int main()
{
	pre();int lastx=0,lasty=0,cnt=0;
	for(int i=1;i<=W;++i)
	{
		if(A[i].y!=lasty)cnt=0;
		else
		{
			++cnt;
			uint t1=C[cnt][k]*C[cntx[A[i].y]-cnt][k];
			uint t2=T.Sum(A[i].x-1)-T.Sum(lastx);
			ans+=t1*t2;
		}
		lastx=A[i].x;lasty=A[i].y;int t=++num[lastx];
		T.Add(lastx,C[t][k]*C[cnty[lastx]-t][k]-C[t-1][k]*C[cnty[lastx]-t+1][k]);
	}
	printf("%d\n",ans&(2147483647));
}