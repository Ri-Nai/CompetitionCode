#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    char s[25];
    int n;
    bool flag1=0,flag2=0;
    void check(int x,int y)
    {
        int cntA=0,cntB=0;
        for(int i=1;i<=n;++i)
        {
            int numA=0,numB=0;
            int j=i;
            while(j<=n and numA<x and numB<x)
            {
                numA+=s[j]=='A';
                numB+=s[j]=='B';
                ++j;
            }
            if(numA==x)++cntA;
            if(numB==x)++cntB;
            if(j==n+1 and(numA!=x and numB!=x))return;
            i=j-1;
            if(cntA==y or cntB==y)
            {
                if(i!=n)return ;
                if(cntA==y)flag1=1;
                if(cntB==y)flag2=1;
            }
        }
    }
    void solve()
    {
        cin>>n>>s+1;
        flag1=flag2=0;
        for(int x=1;x<=n;++x)
            for(int y=1;y<=n;++y)
                check(x,y);
        if(flag1 and flag2)End("-1");
        if(flag1)End("A");
        if(flag2)End("B");
        End("-1");
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
