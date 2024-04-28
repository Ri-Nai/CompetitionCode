#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("Data.in","r",stdin);
    freopen("check.out","w",stdout);
    int n,m;
    cin>>n>>m;
    fclose(stdin);
    freopen("Correct.out","r",stdin);
    int res,num;
    cin>>res>>num;
    vector<vector<int>>ans;
    for(int i=1;i<=num;++i)
    {
        vector<int>now;
        for(int j=1;j<=m;++j)
        {
            int x;cin>>x;
            now.push_back(x);
        }
        ans.push_back(now);
    }
    fclose(stdin);
    freopen("Mine.out","r",stdin);
    int res0;
    cin>>res0;
    if(res0!=res)cout<<"No"<<'\n';
    else
    {
        vector<int>now;
        for(int i=1;i<=m;++i)
        {
            int x;
            cin>>x;
            now.push_back(x);
        }
        for(auto p:ans)
            if(p==now){cout<<"Yes\n";return 0;}
        cout<<"No\n";
    }

}
