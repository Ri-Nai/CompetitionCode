#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int que[N];
    void solve()
    {
        int Q;
        cin>>Q;
        // int head=0,tail=1,last=0;
        priority_queue<int,vector<int>,greater<int> >Q1;
        queue<int>Q2;
        while(Q--)
        {
            int op;
            cin>>op;
            if(op==1)
            {
                int x;
                cin>>x;
                Q2.push(x);
            }
            else if(op==2)
            {
                if(!Q1.empty())
                {
                    cout<<Q1.top()<<'\n';
                    Q1.pop();
                }
                else
                {
                    cout<<Q2.front()<<'\n';
                    Q2.pop();
                }
            }
            else
            {
                while(!Q2.empty())
                {
                    Q1.push(Q2.front());
                    Q2.pop();
                }
            }
        }
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
