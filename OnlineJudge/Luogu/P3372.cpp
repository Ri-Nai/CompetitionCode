#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int A[M],n,m;
struct SegmentTree
{
    long long T[M<<2],lz[M<<2];
    int Build(int L,int R,int p)
    {
        if(L==R)return (T[p]=A[L]);
        int mid=L+R>>1;
        return (T[p]=(Build(L,mid,p<<1)+Build(mid+1,R,p<<1|1)));
    }
    long long query(int l,int r,int L=1,int R=n,int p)
    {
        if(l==L and r==R)return T[p];
        int mid=L+R>>1;
        if(r<=mid)return query(l,r,L,mid,p<<1);
        if(l>mid)return query(l,r,mid+1,R,p<<1|1);
        return query(l,mid,L,mid,p<<1)+query(mid+1,r,mid+1,R,p<<1|1);
    }
    void Modify(int L,int R,int p,int x)
    {
        lz[p]+=x;
        T[p]+=x*(R-L+1);
    }
    void push_down(int L,int R,int p)
    {

    }
    void Add(int l,int r,int L=1,int R=n,int p,int x)
    {
        if(l==L and r==R)return Modify(L,R,p,x);
        int mid=L+R>>1;
        if(r<=mid)Add(l,r,L,mid,p<<1,x);
        else if(l>mid)Add(l,r,mid+1,R,p<<1|1,x);
        else Add(l,mid,L,mid,p<<1,x),Add(mid+1,r,mid+1,R,p<<1|1,x);
        Modify(L,R,p,x);
    }
}Tr;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&A[i]);
    Tr.Build(1,n,1);
    for(int i=1;i<=m;++i)
    {}
}

