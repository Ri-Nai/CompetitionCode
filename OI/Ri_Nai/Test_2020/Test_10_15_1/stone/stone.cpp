#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=5e4+5;
int L,n,m,A[N];
bool chk(int T)
{
	int now=0,cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(A[i]-now<T)
		{
			++cnt;
			if(cnt>m)return 0;
		}
		else now=A[i];
	}
	return 1;
}
int main()
{
//	FILE("stone");
	scanf("%d%d%d",&L,&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	A[++n]=L;
	sort(A+1,A+n+1);
	int l=1,r=L,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	FCLS();
}
/*
25 5 2
2
11
14
17
21

*/
