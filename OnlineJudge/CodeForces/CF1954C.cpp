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
        string s1,s2;
        cin>>s1>>s2;
        int n=s1.size();
        bool flag=0;
        for(int i=0;i<n;++i)
        {
            if(s1[i]!=s2[i])
            {
                if(!flag)
                {
                    flag=1;
                    if(s1[i]<s2[i])swap(s1[i],s2[i]);
                }
                else if(s1[i]>s2[i])swap(s1[i],s2[i]);
            }
        }
        cout<<s1<<'\n'<<s2<<'\n';
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
