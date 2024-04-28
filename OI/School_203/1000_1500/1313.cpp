#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
int n,m,A[1005],mark[1005],mx,id,score=10000,B[1005];
std::vector<int>E,V;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),E.push_back(i);
	while(E.size()>1)
	{
		--score;
		for(int i=0;i<E.size();++i)
		{
			//printf("%d ",E[i]);
			if(i%m==0)mx=0;
			if(A[E[i]]>mx)mx=A[E[i]],id=E[i];
			if((i+1)%m==0||i==E.size()-1)
			{
				for(int j=i/m*m;j<=i;++j)
					if(E[j]!=id)mark[E[j]]=score;
				V.push_back(id);
			}
		}
		//puts("");
		E=V;V.clear();
	}
	mark[E[0]]=--score;
	memcpy(B,mark,sizeof B);
	std::sort(B+1,B+n+1);
	for(int i=1;i<=n;++i)
		printf("%d ",std::lower_bound(B+1,B+1+n,mark[i])-B);
}