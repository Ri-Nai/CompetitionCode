#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
typedef long long Ago;
const int N=1e6+5;
int n,m,k,x;
Ago Qpow(Ago q,Ago p)
{
	Ago res=1;
	for(;p;p>>=1,q=1ll*q*q%n)
		if(p&1)res=1ll*res*q%n;
	return res;
}
int main()
{
	// FILE("circle");
	cin>>n>>m>>k>>x;
	cout<<(1ll*Qpow(10,k)*m+x)%n<<endl;
	FCLS();
}