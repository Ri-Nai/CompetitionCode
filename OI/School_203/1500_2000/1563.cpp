#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool mark[N];
char s[N];
int now,n;
struct node
{
	char ch;
	int pos;
	node(){ch=pos=0;}
	node(char _,int __){ch=_,pos=__;}
	bool operator < (const node &_)const
	{
		if(ch==_.ch)return pos>_.pos;
		return ch<_.ch;
	}
};
string s1,s2;
multiset<node>S;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	now=n;
	for(int i=1;i<=n;++i)
		S.insert(node(s[i],i));
	while(!S.empty())
	{
		while(mark[now])--now;
		mark[now]=1;
		S.erase(node(s[now],now));
		s1+=s[now--];
		s2+=S.begin()->ch;
		mark[S.begin()->pos]=1;
		S.erase(S.begin());
	}
	if(s2<s1)puts("DA");
	else puts("NE");
	cout<<s2<<endl;
}