#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const string A[]={"chimasu","rimasu","mimasu","bimasu","nimasu","kimasu","gimasu","shimasu","imasu"};
    const string B[]={"tte","tte","nde","nde","nde","ite","ide","shite","tte"};
    bool end_with(string a,string b)
    {
        int p=a.size()-b.size();
        if(p<0)return 0;
        for(int i=p,j=0;i<a.size();++i,++j)
            if(a[i]!=b[j])return 0;
        return 1;
    }
    string change(string a,string b,string c)
    {
        int p=a.size()-b.size();
        string res="";
        for(int i=0;i<p;++i)res+=a[i];
        for(int i=0;i<c.size();++i)res+=c[i];
        return res;
    }
    void solve()
    {
        string s;
        cin>>s;
        if(s=="ikimasu")
        {
            cout<<"itte\n";
            return ;
        }
        for(int i=0;i<9;++i)
            if(end_with(s,A[i]))
            {
                cout<<change(s,A[i],B[i])<<'\n';
                return;
            }
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
