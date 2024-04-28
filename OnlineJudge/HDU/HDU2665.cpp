#include<bits/stdc++.h>
using namespace std;
#define ls p<<1
#define rs p<<1|1
const int maxn=1e5+5;
struct node
{
	int L,R;
	vector<int>V;
}Tree[maxn<<2];
int A[maxn],n,m,mn,mx;
void Merge(int A,int B,int C)
{
    Tree[A].V.clear();
    int p=0,q=0,len1=Tree[B].V.size(),len2=Tree[C].V.size();
    while(p<len1&&q<len2)
    {
        if(p<len1&&Tree[B].V[p]<Tree[C].V[q])Tree[A].V.push_back(Tree[B].V[p++]);
        else Tree[A].V.push_back(Tree[C].V[q++]);
    }
    while(p<len1)Tree[A].V.push_back(Tree[B].V[p++]);
    while(q<len2)Tree[A].V.push_back(Tree[C].V[q++]);
}
void build(int L,int R,int p)
{
	Tree[p].L=L;Tree[p].R=R;
    Tree[p].V.clear();
    if(L==R){Tree[p].V.push_back(A[L]);return ;}
    int mid=L+R>>1;
    build(L,mid,ls);build(mid+1,R,rs);
    Merge(p,ls,rs);
}
int query(int L,int R,int x,int p)
{
    if(L==Tree[p].L&&Tree[p].R==R)
    	return upper_bound(Tree[p].V.begin(),Tree[p].V.end(),x)-Tree[p].V.begin();
    int mid=Tree[p].L+Tree[p].R>>1;
    if(R<=mid)return query(L,R,x,ls);
    else if(L>mid)return query(L,R,x,rs);
    return query(L,mid,x,ls)+query(mid+1,R,x,rs);
}
int read()
{
	int t=0,c;
	do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
int main()
{
    int T;T=read();
    while(T--)
    {
    	n=read();m=read();
        mn=1e9,mx=0;
        for(int i=1;i<=n;++i)
        {
        	A[i]=read();
            if(A[i]>mx)mx=A[i];
            else if(A[i]<mn)mn=A[i];
        }
        build(1,n,1);
        while(m--)
        {
            int x=read(),y=read(),z=read();
            int l=mn,r=mx,ans=mn;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(query(x,y,mid,1)>=z)ans=mid,r=mid-1;
                else l=mid+1;
            }
            printf("%d\n",ans);
        }
    }
}