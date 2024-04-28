#include<bits/stdc++.h>
#define LL long long
#define mid (L+R>>1)
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int mod=1e9+7,maxn=1e5+5,maxm=4e5+5;
struct Seg
{
	LL sum[maxm],Add1[maxm],Add2[maxm],len1[maxm],len2[maxm];
	void build(int L,int R,int p)
	{
		len1[p]=R-L+1;
		len2[p]=
		build(L,mid,ls);
		build(mid+1,R,rs);
	}
};
int main()
{

}