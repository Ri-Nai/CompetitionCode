#include<set>
#include<cstdio>
#define IT std::multiset<int>::iterator
std::multiset<int>S;
int T,now,x;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&now);
		if(now==1)scanf("%d",&x),S.insert(x);
		if(now==2)
		{
			scanf("%d",&x);
			if(S.find(x)!=S.end())
				S.erase(S.find(x));
		}
		if(now==3)
		{
			scanf("%d",&x);
			IT it=S.upper_bound(x);
			if(it!=S.end())printf("%d\n",*it);
			else puts("max");
		}
		if(now==4)
		{
			scanf("%d",&x);
			IT it=S.lower_bound(x);
			if(it!=S.begin())--it,printf("%d\n",*it);
			else puts("min");
		}
		if(now==5)
			if(!S.empty())printf("%d\n",*S.rbegin()),S.erase(--S.end());
		if(now==6)
			if(!S.empty())printf("%d\n",*S.begin()),S.erase(S.begin());
	}
	for(int now:S)printf("%d\n",now);
}