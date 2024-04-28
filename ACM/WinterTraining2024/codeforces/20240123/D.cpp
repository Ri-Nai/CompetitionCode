#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int cnt[12],n;
    void solve()
    {
        n=0;
        for(int i=0;i<=9;++i)
            cin>>cnt[i],n+=cnt[i];
        if(n==1 and cnt[0]==1)End(0);
        vector<int>ans;
        int last=0;
        for(int i=1;i<=n;++i)
        {
            int now=n-i+1;
            int mid=now>>1;
            int firstans=-1;
            int alarmans=-1;
            bool first=0;
            for(int j=0;j<=9;++j)
            {
                if(j==last)continue;
                if(!cnt[j])continue;
                if(!first)first=1,firstans=j;
                if(cnt[j]>mid)
                {
                    if(cnt[j]>mid+1)End(-1);
                    if(cnt[j]==mid+1)alarmans=j;
                }
            }
            int res=-1;
            if(alarmans!=-1)res=alarmans;
            else if(first)res=(firstans);
            else End(-1);
            --cnt[res];
            ans.push_back(res);
            last=res;
        }
        for(int i:ans)cout<<i;
        cout<<'\n';
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
