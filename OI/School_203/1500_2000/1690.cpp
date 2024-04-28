#include<bits/stdc++.h>
using namespace std;
const int N=1005;
map<string,int>mp;
char s[N],tmp[N];
string S[N];
int bg,ed,X,n;
int main()
{
	scanf("%d",&X);
	scanf("%s",s+1);
	n=strlen(s+1);
	S[0]=s+1;mp[S[0]]=0;
	s[n]=0;
	for(int i=1;i<=X;++i)
	{
		int cnt=0;
		for(int j=0;j<n;++j)
		{
			if(j&1)s[n-(j+1>>1)]=S[i-1][j];
			else s[cnt++]=S[i-1][j];
		}
		S[i]=s;
		if(i==X)
		{
			cout<<S[i]<<endl;
			return 0;
		}
		if(mp[S[i]])
		{
			bg=mp[S[i]],ed=i;
			break;
		}
		mp[S[i]]=i;
	}
	int now=(X-bg+1)%(ed-bg);
	cout<<S[now];
}