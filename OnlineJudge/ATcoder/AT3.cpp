#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,now;
bool is[N];
int main()
{
	scanf("%d",&n);
	for(int x;n--;)
	{
		scanf("%d",&x);
		is[x]=1;
		while(is[now])++now;
		printf("%d\n",now);
	}
}