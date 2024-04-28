#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,now,f[N];
int main()
{
	scanf("%d",&n);
	if(n==2)return puts("-1"),0;
	for(int i=1;i<n;++i)
		f[i]=i,now+=i;
	f[n]=(n-1)*n-now;now=0;
	for(int i=1;i<=n;++i)
	{
		now+=10000*(f[i]-f[i-1]);
		for(int j=1;j<=n;++j)
			printf("%d ",now+f[j]);
		system("pause");
		puts("");
	}
}