#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
map<string,int>mp;
string T;char s[N];
int A[N],B[N],fail[N],n,m;
int check(int i,int j){return A[i]>=j?0:A[i];}
void read(int *A,int &n)
{
	while(scanf("%s",s),T=s,*s^'$')
		++n,A[n]=!mp[T]?0:n-mp[T],mp[T]=n;
}
int main()
{
	read(A,n);mp.clear();read(B,m);
	fail[0]=fail[1]=0;
	for(int i=2;i<=m;++i)
	{
		int j=fail[i-1];
		while(j&&B[i]!=B[j+1])j=fail[j];
		fail[i]=B[i]==B[j]?j+1:0;
	}
	for(int i=1;i<=m;++i)printf("%d ",B[i]);
	puts("");
	for(int i=1;i<=m;++i)printf("%d ",fail[i-1]);
	for(int i=1,j=0;i<=n;++i)
	{
		while(j&&check(i,j+1)!=B[j+1])j=fail[j];
		if(check(i,j+1)==B[j+1])++j;
		if(j==m)return printf("%d\n",i-m+1),0;
	}
}