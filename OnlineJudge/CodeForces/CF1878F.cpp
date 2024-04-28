#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
const int M=1e6+5;
struct Prime
{
    int x,id,num;
};
vector<Prime>P[M];
vector<int>Pr;
int id[M];
void init()
{
    for(int i=2;i<M;++i)
        if(P[i].empty())
        {
            id[i]=Pr.size();
            P[i].push_back((Prime){i,id[i],1});
            Pr.push_back(i);
            for(int j=i+i;j<M;j+=i)
            {
                int t=j,num=0;
                while(t%i==0)t/=j,++num;
                P[j].push_back((Prime){i,id[i],num});
            }
        }
}
namespace T
{
    int n,q;
    int cnt[M];
    void solve()
    {
        cin>>n>>q;
        int now=n;
        vector<int>list;
        ll prd=1;
        for(int j=0;j<P[now].size();++j)
        {
            cnt[P[now][j].id]=P[now][j].num;
            prd*=P[now][j].num+1;
        }
        while(q--)
        {
            int p;
            cin>>p;
            if(p==1)
            {
                int x;cin>>x;
                for(int j=0;j<P[x].size();++j)
                {
                    int i=P[now][j].id;
                    prd/=cnt[i]+1;
                    if(!cnt[i])list.push_back(i);
                    cnt[i]+=P[now][j].num;
                    prd*=cnt[i]+1;
                }

            }
            else
            {
                now=n;prd=1;
                for(auto T:list)cnt[T]=0;
                list.clear();
                for(int j=0;j<P[now].size();++j)
                {
                    cnt[P[now][j].id]=P[now][j].num;
                    prd*=P[now][j].num+1;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    int t;cin>>t;while(t--)
    T::solve();

}
