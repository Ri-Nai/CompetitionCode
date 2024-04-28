#include<bits/stdc++.h>
using namespace std;
#define ls p<<1
#define rs p<<1|1
#define mid (L+R>>1)
#define Lson L,mid,ls
#define Rson mid+1,R,rs
#define LR int L=1,int R=n,int p=1
#define Min(a,b,c) min(min(a,b),c)
const int N=1e5+5;
class Node
{
public:
	int l,r,s[5],lz;
	Node operator + (const Node &_)const
	{
		Node res;bool t=r==_.l;
		res.l=l;res.r=_.r;
		res.s[0]=Min(s[2]+_.s[1]-t,s[0]+_.s[1],s[2]+_.s[0]);
		res.s[1]=Min(s[]+_.s[])
	}
};
int main()
{
	
}