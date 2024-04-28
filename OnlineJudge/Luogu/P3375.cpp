#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char A[N],B[N];
int n,m,fail[N];
int main()
{
	// scanf("%s%s",A,B);
	// n=strlen(A);
	// m=strlen(B);
	scanf("%s",B);
	m=strlen(B);
	fail[0]=fail[1]=0;
	for(int i=1;i<m;++i)
	{
		int j=fail[i];
		while(j&&B[i]!=B[j])j=fail[j];
		fail[i+1]=B[i]==B[j]?j+1:0;
	}
	// for(int i=0,j=0;i<n;++i)
	// {
	// 	while(j&&A[i]!=B[j+1])j=fail[j];
	// 	if(A[i]==B[j])++j;
	// 	if(j==m)j=fail[j],printf("%d\n",i-m+2);
	// }
	for(int i=0;i<m;++i)printf("%d ",fail[i]);
}