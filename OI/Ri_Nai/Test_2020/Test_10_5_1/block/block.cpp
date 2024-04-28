#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5;
typedef pair<int,int>CP;
int n,A[N],nxt[N],pre[N],ans;
bool mark[N];
void Del(int i)
{
	nxt[pre[i]]=nxt[i];
	pre[nxt[i]]=pre[i];
	mark[i]=1;
}
int main()
{
	// FILE("block");
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&A[i]); 
		nxt[i]=i+1;pre[i]=i-1;
	}
	for(int i=1;i<n;++i)
		if(A[i]==A[i+1])Del(i);
	priority_queue<CP>Q;
	for(int i=1;i<=n;++i)
		if(!mark[i])Q.push(CP(A[i],i));
	while(!Q.empty())
	{
		int i=Q.top().second;Q.pop();
		if(mark[i])continue;
		int nxtv=-1,prev=-1;
		if(nxt[i]!=n+1)nxtv=A[nxt[i]];
		if(pre[i]!=0)prev=A[pre[i]];
		if(~prev||~nxtv)
		{
			ans+=A[i]-max(prev,nxtv);
			Del(i);
			if(prev==nxtv)Del(pre[i]);
		}
		else ans+=A[i];
	}
	cout<<ans<<endl;
    FCLS();
}
/*
5
2 3 4 1 2

*/