#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
typedef long long LL;
LL a,b,x,y;
void Exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b)Exgcd(b,a%b,y,x),y-=a/b*x;
	else x=1,y=0;
}
int main()
{
	FILE("mod");
	cin>>a>>b;
	Exgcd(a,b,x,y);
	cout<<(x%b+b)%b<<endl;
	FCLS();
}