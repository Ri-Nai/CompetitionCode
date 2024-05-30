#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    const int N=5e5+5;
    int n,q,A[N];
    int S[N];
    struct Seg
    {
        ll mx[N<<2],lz[N<<2];
        #define LRP int L=1,int R=n-1,int p=1
        #define ls p<<1
        #define rs p<<1|1
        #define LSON L,mid,ls
        #define RSON mid+1,R,rs
        void Upd(int p,int x)
        {
            mx[p]+=x,lz[p]+=x;
        }
        void PushUp(int p)
        {
            mx[p]=max(mx[ls],mx[rs]);
        }
        void PushDown(int p)
        {
            Upd(ls,lz[p]);
            Upd(rs,lz[p]);
            lz[p]=0;
        }
        void Bulid(LRP)
        {
            lz[p]=0;
            if(L==R)
            {
                mx[p]=S[L]-A[L+1];
                lz[p]=0;
                return ;
            }
            int mid=L+R>>1;
            Bulid(LSON),Bulid(RSON);
            PushUp(p);
        }
        void Update(int l,int r,int x,LRP)
        {
            if(L==l and r==R)return Upd(p,lz[p]);
            PushDown(p);
            int mid=L+R>>1;
            if(r<=mid)Update(l,r,x,LSON);
            else if(l>mid)Update(l,r,x,RSON);
            else Update(l,mid,x,LSON),Update(mid+1,r,x,RSON);
            PushUp(p);
        }
        ll Query(int l,int r,LRP)
        {
            if(L==l and r==R)return mx[p];
            PushDown(p);
            int mid=L+R>>1;
            if(r<=mid)return Query(l,r,LSON);
            if(l>mid)return Query(l,r,RSON);
            return max(Query(l,mid,LSON),Query(mid+1,r,RSON));
        }
    }T;
    struct BIT
    {
        int C[N];
        void clear(){for(int i=1;i<=n;++i)C[i]=0;}
        void Add(int x,int y)
        {
            while(x<=n)C[x]+=y,x+=x&-x;
        }
        ll Sum(int x)
        {
            ll res=0;
            while(x)res+=C[x],x-=x&-x;
            return res;
        }

    }Bit;
    void solve()
    {
        n=rd(),q=rd();
        // cout<<n<<' '<<q<<'\n';
        Bit.clear();
        for(int i=1;i<=n;++i)
            S[i]=S[i-1]+(A[i]=rd());
        for(int i=1;i<=n;++i)Bit.Add(i,A[i]);

        T.Bulid();
        for(int op,x,y;q--;)
        {
            op=rd();x=rd(),y=rd();
            // cout<<op<<'\n';
            if(op==1)
            {
                int d=y-A[x];
                if(x<n)T.Update(x,n-1,d);
                T.Update(x-1,x-1,-d);
                Bit.Add(x,y);
                A[x]=y;
            }
            else cout<<T.Query(x,y-1)-Bit.Sum(x-1)<<'\n';
        }
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
