#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10;
namespace DFS
{
    int n,ans,used[maxn];
    string word[maxn],B;
    bool check(string s,string m,int k)
    {
        int lens=s.size();
        for(int i=0;i<k;++i)
        	if(s[lens-k+i]!=m[i])return 0;
        return 1;
    }
    void Add(string &s,string m,int k)
    {
        int len=m.size();
        for(int i=k;i<len;++i)s+=m[i];
    }
    void dfs(string now)
    {
        ans=max(ans,(int)now.size());
        for(int i=1;i<=n;++i)
        {
            if(used[i]>=2)continue;
            int len=word[i].size();
            for(int j=1;j<=len;++j)
                if(check(now,word[i],j))
                {
                    string tmp=now;
                    Add(tmp,word[i],j);
                    if(tmp==now)continue;
                    used[i]++;dfs(tmp);used[i]--;
                }
        }
        
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>word[i];
        cin>>B;dfs(B);
        cout<<ans<<endl;
    }
}
namespace State_Compression
{
    string word[20];char B;
    int n,ans,dp[17][1<<17],len[20],minus[20][20];
    void pre()
    {
        cin>>n;
        for(int i=0;i<n;++i)
            cin>>word[i],word[i+n]=word[i],
            len[i]=len[i+n]=word[i].size();
        cin>>B;n<<=1;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                const string &S1=word[i],&S2=word[j];
                minus[i][j]=-0x3f3f3f3f;
                for(int k=1;k<len[i]&&k<len[j];++k)
                    if(S1.substr(len[i]-k)==S2.substr(0,k))
                    {
                        // printf("[%d] [%d]->%d\n",i,j,
                            minus[i][j]=k
                            // )
                            ;
                        break;
                    }
            }
        memset(dp,-0x3f,sizeof dp);
        for(int i=0;i<n;++i)
            if(word[i][0]==B)dp[i][1<<i]=len[i];
    }
    void solve()
    {
        pre();
        for(int i=0;i<(1<<n);++i)
            for(int j=0;j<n;++j)if(((i>>j)&1)&&dp[j][i]>0)
            {
                ans=max(ans,dp[j][i]);
                for(int k=0;k<n;++k)if(((i>>k)&1^1)&&minus[j][k]>0)
                    ans=max(ans,dp[k][i|(1<<k)]=
                        max(dp[k][i|(1<<k)],dp[j][i]+len[k]-minus[j][k]))
                    // ,
                    // printf("i=%d j=%d k=%d dp[j][i]=%d dp[k][i|(1<<k)]=%d len[k]=%d minus[j][k]=%d\n",
                    //    i,j,k,dp[j][i],dp[k][i|(1<<k)],len[k],minus[j][k])
                    ;
        
            }
        printf("%d\n",ans);
    }


}
int main()
{
    State_Compression::solve();
}