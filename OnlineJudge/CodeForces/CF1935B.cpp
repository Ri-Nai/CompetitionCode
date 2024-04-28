#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
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
    void solve()
    {
        int n=rd();
        struct mex
        {
            int val;
            vector<int>cnt;
            void init(int n){val=0;cnt.assign(n+1,0);}
            void Add(int x)
            {
                ++cnt[x];
                while(cnt[val])++val;
            }
            void Dec(int x)
            {
                if(!--cnt[x])
                    if(x<val)val=x;
            }
        }X,Y;
        X.init(n);Y.init(n);
        vector<int>A;
        for(int i=1;i<=n;++i)
            A.push_back(rd());
        for(int i=0;i<n;++i)
            Y.Add(A[i]);
        for(int i=0;i<n-1;++i)
        {
            X.Add(A[i]);
            Y.Dec(A[i]);
            if(X.val==Y.val)
            {
                printf("2\n1 %d\n%d %d\n",i+1,i+2,n);
                return ;
            }
        }
        puts("-1");
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
