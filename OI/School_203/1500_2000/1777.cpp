#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int dp[N],ans,len;
char s[N];
struct Trie
{
	int Trie[N>>7][26];
	int num[N],tot;
	void Insert(int x)
	{
	    int now=0;
	    for(int i=0;i<len;++i)
	    {
	        int id=s[i]-'A';
	        if(!Trie[now][id])Trie[now][id]=++tot;
	        now=Trie[now][id];
	    }
	    num[now]=x;
	}
	int move(int &now,char c)
	{
		int id=c-'A';
		if(!Trie[now][id])return -1;
		return num[now=Trie[now][id]];
	}
}L,R;
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);len=strlen(s);
		int l=0,r=0,lp,rp,res=0;
		for(int j=0,k=len-1;j<len;++j,--k)
		{
			lp=L.move(l,s[j]);
			rp=R.move(r,s[k]);
			if(lp==-1||rp==-1)break;
			if(lp==rp)res=max(res,dp[rp]);
		}
		L.Insert(i);
		for(int j=0,k=len-1;j<k;++j,--k)swap(s[j],s[k]);
		R.Insert(i);
		ans=max(dp[i]=res+1,ans);
	}
	printf("%d\n",ans);
}