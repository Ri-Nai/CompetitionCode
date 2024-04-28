#include<bits/stdc++.h>
using namespace std;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(res<<1)+(res<<3)+(c^48),c=getchar();
    return res*f;
}
namespace T
{
    const int N=505;
    string Name[N],ans[N];
    struct Stu
    {
        int id;
        string name;
        int score;
        vector<string>list;
        void input(int i)
        {
            id=i;
            cin>>name>>score;
            Name[i]=name;
            int m;
            cin>>m;
            for(int i=1;i<=m;++i)
            {
                string s;
                cin>>s;
                list.push_back(s);
            }

        }
        bool operator <(const Stu &_)const
        {
            return score>_.score;
        }
    }E[N];
    map<string,int>val;
    void Solve()
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            E[i].input(i);
        sort(E+1,E+n+1);
        for(int i=1;i<=m;++i)
        {
            string s;
            int x;
            cin>>s>>x;
            val[s]=x;
        }
        for(int i=1;i<=n;++i)
        {
            for(string s:E[i].list)
            {
                if(val[s])
                {
                    --val[s];
                    ans[E[i].id]=s;
                    break;
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(ans[i].empty())ans[i]='?';
            cout<<Name[i]<<' '<<ans[i]<<'\n';
        }

    }
}
int main()
{
    ios::sync_with_stdio(0);
    T::Solve();
}
