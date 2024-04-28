#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5;
int n,X,Y,ans=-1;
struct SQR
{
	int x,y,a,b;
	void read()
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
	}
	void chk(int id)
	{
		if(x<=X&&x+a>=X&&y<=Y&&y+b>=Y)ans=id;
	}
}A[N];
int main()
{
	// FILE("carpet");
	cin>>n;
	for(int i=1;i<=n;++i)A[i].read();
	cin>>X>>Y;
	for(int i=1;i<=n;++i)A[i].chk(i);
	cout<<ans<<endl;
	FCLS();
}