#include<bits/stdc++.h>
using namespace std;
struct node
{
	string s;
	bool operator <(const node &_)const
	{
		if(s.size()==_.s.size())return s>_.s;
		return s.size()>_.s.size();
	}
};
priority_queue<node>S;
char s[105];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		int len=strlen(s),now=0;
		while(now<len)
		{
			if(isdigit(s[now]))
	        {
	            string res;
	            while(now<len&&s[now]=='0')++now;
	            while(now<len&&isdigit(s[now]))res+=s[now++];
	            if(res.empty())res="0";
	            S.push((node){res});
	            continue;
	        }
	        ++now;
		}
	}
	while(!S.empty())
		cout<<S.top().s<<endl,S.pop();
}