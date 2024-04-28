#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,mn=1e9,Mn[N];
struct node
{
    int A,B;
    void read()
    {
        scanf("%d%d",&A,&B);
    }
}P[N];
bool cmp(node a,node b)
{   
    return a.B<b.B;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)P[i].read();
    sort(P+1,P+n+1,cmp);
	Mn[n+1]=2e9;
	for(int i=n;i;--i)
		Mn[i]=min(Mn[i+1],P[i].A);
	long long now=0;
	for(int i=1;i<=n;++i)
	{
		mn=min(mn,P[i].A-P[i].B);
		printf("%lld\n",min(now+P[i].B+mn,now+Mn[i+1]));
		now+=P[i].B;
	}
}
/*
6
1 1
8 1
1 4
4 5
1 9
1 9
3
3 2
5 3
6 6
*/