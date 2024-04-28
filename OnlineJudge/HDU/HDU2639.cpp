#include<cstdio>
#include<set>
int n,V,K,v[105],w[105];
std::set<int>S[1005];
void solve()
{
	scanf("%d%d%d",&n,&V,&K);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);	
	//for(int i=0;i<=V;++i)S[i].insert(0);
	for(int i=0;i<=1000;++i)S[i].clear();
	S[0].insert(0);
	for(int i=1;i<=n;++i)
		for(int j=V;j>=v[i];--j)
		{
			for(std::set<int>::iterator it=S[j-v[i]].
				begin();it!=S[j-v[i]].end();++it)
			{
				S[j].insert(*it+w[i]);
				if(S[j].size()>K)S[j].erase(S[j].begin());
			}
		}
	std::set<int>ans;
	for(int i=V;i>=0;--i)
		{
			for(std::set<int>::iterator it=S[i].
				begin();it!=S[i].end();++it)
			{
				ans.insert(*it);
				if(ans.size()>K)ans.erase(ans.begin());
			}
		}
	if(ans.size()!=K)puts("0");
	else printf("%d\n",*ans.begin());

}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}
/*
#include<bits/stdc++.h>
using namespace std;
int T;
int n,v,k;
int a[10005];
int b[10005];
set<int>Q[1005];
set<int>:: iterator itr;
int main(){	
	cin>>T;
	while(T--){
		for(int i=1;i<=1000;i++)Q[i].clear();
		scanf("%d%d%d",&n,&v,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		Q[0].insert(0);
		for(int i=1;i<=n;i++)
			for(int j=v;j>=b[i];j--)
				for(itr=Q[j-b[i]].begin();itr!=Q[j-b[i]].end();itr++){
					//cout<<1;
					Q[j].insert(*itr+a[i]);
					if(Q[j].size()>k)Q[j].erase(Q[j].begin());
				}
		set<int>ans;
		for(int j=v;j>=0;j--)
			for(itr=Q[j].begin();itr!=Q[j].end();itr++){
				ans.insert(*itr);
				if(ans.size()>k)ans.erase(ans.begin());
			}
		if(ans.size()!=k)printf("0\n");
		else printf("%d\n",*ans.begin());
	}	
}

*/