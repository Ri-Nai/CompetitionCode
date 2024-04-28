#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%x",&x);
		if(x<48)putchar('.');
		else putchar('-');
	}
}