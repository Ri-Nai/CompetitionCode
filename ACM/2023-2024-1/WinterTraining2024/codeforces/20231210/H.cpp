#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,t;
struct Edge
{
    int v,w;
};
struct Point
{
    int u;
    double w;
    bool operator <(const Point &_)const
    {
        return w>_.w;
    }
};
vector<Edge>E[N];
string S[N];
int dis[N],id[N];
int in[N],vis[N];
bool cmp(int u,int v)
{
    return dis[u]>dis[v];
}
bool SPFA()
{
    queue<int>Q;
    // Q.push(x);
    // vis[x]=1;
    for(int i=1;i<=26;++i)Q.push(i),vis[i]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        vis[u]=0;
        for(auto t:E[u])
        {
            int v=t.v,w=t.w;
            // cout<<v<<' '<<w<<'\n';
            if(dis[u]+w<dis[v])
            {
                if(!vis[v])
                {
                    vis[v]=1;
                    Q.push(v);
                    ++in[v];
                    if(in[v]>30)return 1;
                }
                dis[v]=dis[u]+w;
            }
        }
    }
    return 0;
}
void Solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>S[i];
    for(int i=1;i<n;++i)
    {
        bool flag=1;
        int l=min(S[i].size(),S[i+1].size());
        for(int j=0;j<l;++j)
        {
            if(S[i][j]==S[i+1][j])continue;
            flag=0;
            E[S[i][j]-'a'+1].push_back((Edge){S[i+1][j]-'a'+1,-1});
            break;
        }
        if(flag and S[i].size()>S[i+1].size())
        {
            cout<<"impossible\n";
            return ;
        }
    }
    // cout<<"AAA\n";
    if(SPFA())
    {
        cout<<"impossible\n";
        return ;
    }
    for(int i=1;i<=26;++i)id[i]=i;
    // for(int i=1;i<=26;++i)cout<<dis[i]<<'\n';
    sort(id+1,id+26+1,cmp);
    for(int i=1;i<=26;++i)
        cout<<char(id[i]+'a'-1);
    // cout<<dis[3]<<'\n';

}
int main()
{
    ios::sync_with_stdio(0);
    Solve();
}
/*
a-b=1  -1
b-a=1  -1
*/
