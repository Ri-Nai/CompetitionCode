#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=1e6+5;
const ULL base=19260817;
map<string,int>mp;
string T;char s[N];
ULL HA,HB,pw[N];
int A[N],B[N],Na[N],Nb[N],n,m;
int check(int i,int j){return A[i]>=j?0:A[i];}
void read(int *A,int *nxt,int &n)
{
	while(scanf("%s",s),T=s,*s^'$')
	{
		++n;if(!mp[T])A[n]=0;
		else A[n]=n-mp[T],nxt[mp[T]]=n;
		mp[T]=n;
	}
}
int main()
{
	read(A,Na,n);mp.clear();read(B,Nb,m);pw[0]=1;
	for(int i=1;i<=m;++i)
		pw[i]=pw[i-1]*base,
		HA=HA*base+A[i],
		HB=HB*base+B[i];
	if(HA==HB)return puts("1"),0;
	for(int i=1;i<=n-m;++i)
	{
		HA-=pw[m-1]*A[i];
		HA=HA*base+A[i+m];
		if(Na[i]&&Na[i]<=i+m)HA-=pw[m-Na[i]+i]*A[Na[i]];
		A[Na[i]]=0;
		if(HA==HB)return printf("%d\n",i+1),0;
	}

}