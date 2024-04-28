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
        int n=rd();
        vector<vector<int>>cnt(n+1);
        vector<vector<int>>pre(n+1);
        vector<int>len(n+1),prelen(n+1);
        for(int i=1;i<=n;++i)
        {
            char c;
            cnt[i].assign(26,0);
            pre[i].assign(26,0);
            while((c=getchar())!='\n')
                ++cnt[i][c-'a'],++len[i];
        }
        prelen[n]=len[n];
        pre[n]=cnt[n];
        for(int i=n;i>=2;--i)
        {
            int l1=len[i-1];
            int l2=len[i];
            int pl=prelen[i];
            int p=l2/l1,q=l2%l1;
            int u=pl/l1,v=pl%l1;
            prelen[i-1]=max(v,q);
            int now=0;
            for(int j=0;j<26;++j)
            {
                int t1=cnt[i][j]-p*cnt[i-1][j];
                int t2=pre[i][j]-u*cnt[i-1][j];
                // cout<<i<<' '<<j<<' '<<'\n';
                if(t1<0 or t2<0)End("NO");
                if(v>q and t1>t2)End("NO");
                if(q>v and t2>t1)End("NO");
                pre[i-1][j]=max(t1,t2);
                now+=pre[i-1][j];
                if(cnt[i-1][j]<pre[i-1][j])End("NO");
            }
            if(now!=prelen[i-1])End("NO");
        }
        puts("YES");
        string s;
        for(int j=0;j<26;++j)
            for(int k=1;k<=pre[1][j];++k)
                s+=j+'a';
        for(int j=0;j<26;++j)
            for(int k=1;k<=cnt[1][j]-pre[1][j];++k)
                s+=j+'a';
        for(int i=1;i<=n;++i)
        {
            string t;
            for(int j=0;j<len[i];++j)
                t+=s[j%s.size()];
            cout<<t<<'\n';
            s=t;
        }
    }
}
bool Ri;
int main()
{
    int t;cin>>t;while(t--)
    T::solve();
}
