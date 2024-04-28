#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,A[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	int bg=1,ed=n,num=0;
	while(bg<ed)
	{
		while(bg<ed&&A[bg]!=A[ed])
		{
			if(A[bg]<A[ed])A[bg+1]+=A[bg],++bg;
			else A[ed-1]+=A[ed],--ed;
			++num;
		}
		++bg,--ed;
	}
	printf("%d\n",num);
}