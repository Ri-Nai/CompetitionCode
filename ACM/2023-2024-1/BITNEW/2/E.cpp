#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    int n;
    const int M=1e3+5;
    const int P=1e9+7;
    struct pr
    {
        int x,y;
        bool operator <(const pr &_)const
        {
            if(x==_.x)return y<_.y;
            return x<_.x;
        }
        void input()
        {
            cin>>x>>y;
        }
        ll calc()
        {
            ll val=(x+1)*2005+(y+1);
            return val;
        }
    }A[M];
    struct Blk
    {
        int num;
        ull hsh;

        bool operator <(const Blk &_)const
        {
            if(num==_.num)return hsh<_.hsh;
            return num<_.num;
        }
        void input()
        {
            cin>>num;
            for(int i=1;i<=num;++i)
                A[i].input();
            sort(A+1,A+num+1);
            for(int i=2;i<=num;++i)
            {
                A[i].x-=A[1].x;
                A[i].y-=A[1].y;
                A[i].calc();
            }
            A[1].x=A[1].y=0;
            hsh=0;
            for(int i=1;i<=num;++i)
                hsh=hsh*P+A[i].calc();
        }
    }t;
    set<Blk>S;
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            t.input();
            S.insert(t);
        }
        cout<<S.size();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    T::solve();

}
