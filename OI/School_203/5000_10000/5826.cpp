#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,len,A[N],B[N],ans,pos[N],nxt[N];
struct node
{
	int nxt,val;
	bool operator <(const node &_)const
	{
		return nxt>_.nxt;
	}
};
multiset<node>S;
bool in[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i];
	sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)pos[A[i]=lower_bound(B+1,B+len+1,A[i])-B]=n+1;
	for(int i=n;i;--i)nxt[i]=pos[A[i]],pos[A[i]]=i;
	for(int i=1;i<=n;++i)
	{
		int now=A[i];
		if(!in[now])
		{
			++ans;
			if(S.size()>=m)
			{
				in[S.begin()->val]=0;
				S.erase(S.begin());
			}
			S.insert((node){nxt[i],now});
			in[now]=1;
		}
		else 
		{
			S.erase((node){i,now});
			S.insert((node){nxt[i],now});

		}
	}
	printf("%d\n",ans);
}