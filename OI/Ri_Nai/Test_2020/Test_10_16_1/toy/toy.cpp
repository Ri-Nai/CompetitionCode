#include<bits/stdc++.h>
using namespace std;
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5;
int n,m,A[N],now;
char s[N];
string S[N];
int main()
{
//	FILE("toy");
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	{	
		scanf("%d",&A[i]);
		scanf("%s",s);
		S[i]=string(s);
	}
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		int p=A[now]^x;
		if(p)now=(now+y+n)%n;
		else now=(now-y+n)%n;
	}
	cout<<S[now]<<endl;
}
/*
7 3
0 singer
0 reader
0 mengbier
1 thinker
1 archer
0 writer
1 mogician
0 3
1 1
0 2


10 10
1 c
0 r
0 p
1 d
1 e
1 m
1 t
1 y
1 u
0 v
1 7
1 1
1 4
0 5
0 3
0 1
1 6
1 2
0 8
0 4

*/
