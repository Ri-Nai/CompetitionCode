#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int cnt[256],num[256],n;
char A[N],B[N];
int main()
{
	scanf("%d\n%s\n%s",&n,A+1,B+1);
	for(int i=1;i<=n;++i)++cnt[A[i]],++num[B[i]];
	for(int i=1;i<=n;++i)
	{
		--num[B[i]];
		for(char c='a';c<='c';++c)
		{
			if(c==B[i])continue;
			if(!cnt[c])continue;
			bool flag=1;--cnt[c];
			for(int j='a';j<='c';++j)
			{
				int now=0;	
				for(int k='a';k<='c';++k)
					if(k!=j)now+=cnt[k];
				if(now<num[j]){flag=0;break;}
			}
			if(!flag&&++cnt[c])continue;
			else putchar(c);
			break;
		}
	}
}