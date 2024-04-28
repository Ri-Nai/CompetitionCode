#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
const int P=19260817,N=2e6+5;
map<ULL,int>mp;
char s[N];
ULL p[N];
int len,n,ans;
int main()
{
	scanf("%d",&n);
	p[0]=1;
	for(int i=1;i<N;++i)p[i]=p[i-1]*P;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		len=strlen(s);
		int res=0;
		ULL l=0,r=0;
		for(int j=0,k=len-1;j<len;++j,--k)
		{
			l=l*P+s[j];r+=p[j]*s[k];
			if(l==r)res=max(mp[l],res);
		}
		ans=max(mp[l]=res+1,ans);
	}
	printf("%d\n",ans);
}