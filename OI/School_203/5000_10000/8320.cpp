#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=3e5+5,maxm=550;
int n,ans[maxn];
struct BIT
{
	int C[maxn];
	BIT(){memset(C,0x3f,sizeof C);}
	void ToMin(int x,int y)
	{
		while(x)
		{
			if(y<C[x])C[x]=y;
			x-=x&-x;
		}
	}
	int GetMin(int x)
	{
		if(!x)x=1;
		int res=1e7;
		while(x<maxn)
		{
			if(C[x]<res)res=C[x];
			x+=x&-x;
		}
		return res;
	}
}T;
int main()
{
	memset(ans,0x3f,sizeof ans);
	scanf("%d",&n);char s[2];int x;
	while(n--)
	{
		scanf("%s%d",s,&x);
		if(*s=='A')
		{
			for(int i=1;i<=maxm;++i)
				ans[i]=std::min(ans[i],x%i);
			T.ToMin(x,x);
		}
		else
		{
			if(x>maxm)
				for(int i=0;i<maxn;i+=x)
					ans[x]=std::min(ans[x],T.GetMin(i)-i);
			printf("%d\n",ans[x]);
		}
	}
};