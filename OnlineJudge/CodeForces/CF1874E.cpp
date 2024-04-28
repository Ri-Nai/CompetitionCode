#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pr;
typedef pair<Pr,int> PPr;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    int a,b,c,d,m;
    map<PPr,bool>mk;
    queue<PPr>Q;
    void Push(PPr x)
    {
        if(mk[x])return;
        mk[x]=1;
        Q.push(x);
    }
    void solve()
    {
        cin>>a>>b>>c>>d>>m;
        mk.clear();
        while(!Q.empty())Q.pop();
        Push(PPr(Pr(a,b),0));
        while(!Q.empty())
        {
            PPr T=Q.front();
            Q.pop();
            // if(m==39 and T.second<5)cout<<T.first.first<<' '<<T.first.second<<'\n';
            if(T.first==Pr(c,d))End(T.second);
            if(T.second>100)End("-1");
            PPr tmp=T;
            ++tmp.second;
            tmp.first.first=T.first.first&T.first.second;
            Push(tmp);
            tmp.first=T.first;
            tmp.first.first=T.first.first|T.first.second;
            Push(tmp);
            tmp.first=T.first;
            tmp.first.second=T.first.first^T.first.second;
            Push(tmp);
            tmp.first=T.first;
            tmp.first.second=T.first.second^m;
            Push(tmp);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
