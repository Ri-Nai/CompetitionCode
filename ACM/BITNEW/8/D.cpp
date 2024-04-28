#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n;
    const int N=1<<12;
    int Max(int n)
    {
        int ans=-1;
        for(int i=2;i*i<=n;++i)
        {
            if(n%i==0)ans=n/i;
        }
        return ans;
    }
    ll check(int x,int y,int z)
    {
        return 1ll*(x+1)*(y+1)*(z+1)-1ll*x*y*z-1;
    }
    int Get(int x,int y)
    {
        int l=0,r=4096,ans=-1;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(check(x,y,mid)>=n)
                r=mid-1,ans=mid;
            else l=mid+1;
        }
        if(check(x,y,ans)==n)return ans;
        return -1;

    }
    void Put(int n,char c)
    {
        for(int i=1;i<=n;++i)putchar(c);
    }
    void solve()
    {
        cin>>n;
        for(int x=0;x<=N;++x)
        {
            for(int y=0;y<=N;++y)
            {
                if(x+y>N)break;
                int z=Get(x,y);
                if(~z)
                {
                    if(x+y+z<=N)
                    {
                        Put(x,'a');
                        Put(y,'b');
                        Put(z,'c');
                        return;
                    }
                }
            }
        }
        End("-1");
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
/*
aaaabbbbccccc
x*(y+z)+y*z+x+y+z
(x+1)(y+1)(z+1)
xyz+xy+xz+zy+x+y+z+1
*/
