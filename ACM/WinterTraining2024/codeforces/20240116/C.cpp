#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n;
    const int N=2e5+5;
    ll dp[N];
    struct Pr
    {
        ll t,val;
        void input()
        {
            cin>>t>>val;
        }
        bool operator <(const Pr &_)const
        {
            return t>_.t;
        }
    };
    void Solve()
    {
        vector<Pr>E;
        // cin>>n;
        for(int i=1;i<=n;++i)
        {
            Pr tmp;
            tmp.input();
            while(!E.empty() && E.back().val<=tmp.val)
                E.pop_back();
            E.push_back(tmp);
            // cout<<E.back().t<<' '<<E.back().val<<'\n';
        }
        // printf("aaa%d\n",E.size());
        // cout<<E.size()<<'\n';
        int now=0;
        priority_queue<Pr>Q;
        for(int i=0;i<E.size();++i)
        {
            while(now<i and dp[now]<=E[i].t)++now;
            dp[i]=E[i].t+2*E[now].val;
            while(!Q.empty())
            {
                Pr p=Q.top();
                if(p.t<=E[i].t+2*E[p.val+1].val)Q.pop();
                else
                {
                    // cout<<p.t<<"aaa\n";
                    dp[i]=min(dp[i],p.t);
                    // cout<<"AAA\n";
                    break;
                }
            }
            // cout<<dp[i]<<"**\n";
            if(i!=E.size()-1)
            {
                Q.push((Pr){dp[i]+2*E[i+1].val,i});
                // cout<<dp[i]<<"\n";
                // cout<<E[i+1].val<<"\n";
                // cout<<dp[i]+E[i+1].val*2<<"|||\n";
            }
        }
        cout<<dp[E.size()-1]<<'\n';
    }
    void solve()
    {
        while(cin>>n)Solve();
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
