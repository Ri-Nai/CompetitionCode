#include<bits/stdc++.h>
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define FCLS() fclose(stdin);fclose(stdout);
using namespace std;
const int N=205,WIN[5][5]=
{
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,0,1},
	{0,0,1,0,1},
	{1,1,0,0,0}
};
int n,nA,nB,A[N],B[N],sum1,sum2;
int main()
{
	// FILE("rps");
	scanf("%d%d%d",&n,&nA,&nB);
	for(int i=0;i<nA;++i)scanf("%d",&A[i]);
	for(int i=0;i<nB;++i)scanf("%d",&B[i]);
	for(int i=0;i<n;++i)
	{
		int ka=i%nA,kb=i%nB;
		if(WIN[A[ka]][B[kb]])++sum1;
		if(WIN[B[kb]][A[ka]])++sum2;
	}
	printf("%d %d\n",sum1,sum2);
	FCLS();return 0;
}