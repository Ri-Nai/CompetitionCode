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
        char s[105][105];
        int n=rd(),m=rd(),x=rd(),y=rd();
        --x,--y;
        for(int i=0;i<n;++i)
            scanf("%s",s[i]);
        int p=rd(),q=rd();
        vector<Pr>op;
        while(q--)
        {
            int x=rd(),y=rd();
            op.push_back({x,y-1});
        }
        while(p--)
            for(auto [x,y]:op)
            {
                if(x==1)
                {
                    vector<char>tmp;
                    for(int i=0;i<m;++i)
                        tmp.push_back(s[y][(i+m-1)%m]);
                    for(int i=0;i<m;++i)
                        s[y][i]=tmp[i];
                }
                else
                {
                    vector<char>tmp;
                    for(int i=0;i<n;++i)
                        tmp.push_back(s[(i+m-1)%m][y]);
                    for(int i=0;i<n;++i)
                        s[i][y]=tmp[i];
                }
            }
        cout<<s[x][y]<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
