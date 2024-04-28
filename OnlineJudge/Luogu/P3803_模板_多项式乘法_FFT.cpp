#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace FFT
{
    const double pi=asin(1)*2;
    struct Comp
    {
        double a,b;
        Comp(double _=0,double __=0):a(_),b(__){}
        Comp operator + (const Comp &_)const
        {
            return {a+_.a,b+_.b};
        }
        Comp operator - (const Comp &_)const
        {
            return {a-_.a,b-_.b};
        }
        Comp operator * (const Comp &_)const
        {
            return {a*_.a-b*_.b,a*_.b+b*_.a};
        }
    };

    void solve()
    {
        int l1=rd(),l2=rd(),len=1,bit=0;
        while(len<=l1+l2)len<<=1,++bit;
        vector<int>idx(len);
        for(int i=1;i<len;++i)
            idx[i]=idx[i>>1]>>1|(i&1)<<bit-1;
        vector<Comp>A,B,C;
        for(int i=0;i<=l1;++i)A.push_back({rd(),0});
        for(int i=0;i<=l2;++i)B.push_back({rd(),0});
        A.resize(len),B.resize(len);
        auto FFT=[&](auto self,vector<Comp> &T,int p)->void
        {
            int n=T.size(),m=n>>1;
            if(n==1)return ;
            vector<Comp>X,Y;
            for(int i=0;i<n;i+=2)
                X.push_back(T[i]),Y.push_back(T[i|1]);
            self(self,X,p);self(self,Y,p);
            Comp W0(cos(2*pi/n),sin(2*pi/n)*p),W(1,0);
            for(int i=0;i<m;++i,W=W*W0)
                T[i]=X[i]+W*Y[i],T[i+m]=X[i]-W*Y[i];
        };
        auto FFT_=[&](vector<Comp> &T,int p)->void
        {
            int len=T.size();
            for(int i=0;i<len;++i)
                if(i<idx[i])swap(T[i],T[idx[i]]);
            for(int m=1;m<len;m<<=1)
            {
                // cout<<m<<'\n';
                int n=m<<1;
                Comp W0(cos(2*pi/n),sin(2*pi/n)*p);
                for(int j=0;j<len;j+=n)
                {
                    Comp W(1,0);
                    for(int i=j;i<j+m;++i,W=W*W0)
                    {
                        Comp X=T[i],Y=W*T[i+m];
                        T[i]=X+Y,T[i+m]=X-Y;
                    }
                }
            }
        };

        FFT_(A,1);FFT_(B,1);
        for(int i=0;i<len;++i)
            C.push_back(A[i]*B[i]);
        FFT_(C,-1);
        for(int i=0;i<=l1+l2;++i)
            printf("%d%c",int(C[i].a/len+0.5)," \n"[i==l1+l2]);
    }
}
namespace NTT
{
    const int P=998244353;
    int Qpow(int x,int n)
    {
        int res=1;
        for(;n;n>>=1,x=1ll*x*x%P)
            if(n&1)res=1ll*x*res%P;
        return res;
    }
    const int G=114514,G_=Qpow(G,P-2);
    void Solve()
    {
        int n=rd(),m=rd();
        int T=1,bit=0;
        while(T<=n+m)T<<=1,++bit;
        vector<int>idx(T);
        for(int i=1;i<T;++i)
            idx[i]=idx[i>>1]>>1|(i&1)<<bit-1;
        vector<int>A,B,C;
        for(int i=0;i<=n;++i)A.push_back(rd());
        for(int i=0;i<=m;++i)B.push_back(rd());
        A.resize(T);B.resize(T);
        auto NTT=[&](vector<int>&T,int g)
        {
            int len=T.size();
            for(int i=0;i<len;++i)
                if(i<idx[i])swap(T[i],T[idx[i]]);
            for(int p=1,m=1;m<len;++p,m<<=1)
            {
                int W0=Qpow(g,(P-1)>>p);
                for(int i=0;i+m<len;i+=m<<1)
                {
                    int W=1;
                    for(int j=i;j<i+m;++j,W=1ll*W*W0%P)
                    {
                        int X=T[j],Y=1ll*W*T[j+m]%P;
                        T[j]=(X+Y)%P;
                        T[j+m]=(0ll+X-Y+P)%P;
                    }
                }
            }
        };
        NTT(A,G);NTT(B,G);
        for(int i=0;i<T;++i)
            C.push_back(1ll*A[i]*B[i]%P);
        NTT(C,G_);
        int inv=Qpow(T,P-2);
        for(int i=0;i<=n+m;++i)
            printf("%lld ",1ll*C[i]*inv%P);
    }
}
int main()
{
    // FFT::solve();
    NTT::Solve();
}
