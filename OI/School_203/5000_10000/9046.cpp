#include<bits/stdc++.h>
using namespace std;
typedef long long Ago;
int n;Ago w,k;
multiset<Ago>S;
Ago rd()
{
	Ago t=0;int c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
void solve()
{
	
}
int main()
{
	n=rd();
	for(int i=1;i<=n;++i)
		S.insert(rd());
	for(int Q=rd(),opt;Q--;)
	{
		opt=rd();w=rd();
		if(opt==1)k=rd(),solve();
		else if(opt==2)S.insert(w);
		else S.erase(w);
	}
}