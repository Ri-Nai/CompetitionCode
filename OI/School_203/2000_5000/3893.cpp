#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,mod=31536000;
struct node
{
	int A,B;
	void read(){scanf("%d%d",&A,&B);}
	bool operator < (node _)const
	{
		return 1ll*A*_.B<1ll*B*_.A;
	}
}P[maxn];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)P[i].read();
	sort(P+1,P+n+1);long long now=0;
	for(int i=1;i<=n;++i)
		(now+=1ll*P[i].A+1ll*P[i].B*now)%=mod;
	printf("%lld\n",now);
}