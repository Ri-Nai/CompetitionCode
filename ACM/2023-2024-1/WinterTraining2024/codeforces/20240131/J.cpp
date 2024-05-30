#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    void check(int x,int y)
    {

        for(int a=2;a<x;++a)
            for(int b=2;b<y;++b)
            {
                int l=x,r=y;
                bool flag=1;
                while(flag and (l or r))
                {
                    if(l%a!=r%b)flag=0;
                    l/=a,r/=b;
                }
                if(flag)
                {
                    cout<<a<<' '<<b<<'\n';
                    // return ;
                }
            }
        cout<<"***************\n";
    }
    void solve()
    {
        freopen("11.txt","w",stdout);
        for(int i=1;i<=100;++i)
            for(int j=i+1;j<=100;++j)
            {
                cout<<i<<' '<<j<<'\n';
                check(i,j);
            }
        // check(10126,114514);
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
