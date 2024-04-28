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
        vector<int>A(n+1);
        for(int i=1;i<=n;++i)
            A[i]=rd();
        int last=-1;
        for(int i=1;i<=n;++i)
        {
            if(A[i]<=10)
            {
                if(A[i]<last)return puts("NO"),void();
                last=A[i];
            }
            else
            {
                if(A[i]/10<=A[i]%10 and A[i]/10>=last)
                    last=A[i]%10;
                else if(A[i]>=last)last=A[i];
                else return puts("NO"),void();
            }
        }
        puts("YES");
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
