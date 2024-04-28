#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,q;
    const int N=5005;
    int A[N],L[N],R[N],pre[N],nxt[N];
    int rd()
    {
        int res=0,f=1;char c;
        do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
        while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
        return res*f;
    }
    void Solve()
    {
        int m=rd();
        int last=0;
        L[0]=R[0]=0;
        for(int i=1;i<=n;++i)
            L[i]=R[i]=pre[i]=nxt[i]=-1;
        bool flag=0;
        for(int i=1;i<=m;++i)
        {
            int x=rd();
            if(x && pre[x]!=-1)flag=1;
            if(last && nxt[last]!=-1)flag=1;
            pre[x]=last;
            nxt[last]=x;
            last=x;
            if(i==m)nxt[x]=0;
        }
        if(flag)End("No");
        nxt[0]=pre[0]=-114514;
        int cnt=0,now=0;
        for(int i=1;i<=n;++i)
            cnt+=nxt[i]==R[i];
        if(cnt==n)End("Yes");
        for(int i=1;i<=n;++i)
        {
            int p=A[i];
            auto Del=[&](int q)
            {
                if(R[q]==nxt[q])--cnt;
                if(R[L[q]]==nxt[L[q]])--cnt;
                R[L[q]]=R[q];
                L[R[q]]=L[q];
                if(R[L[q]]==nxt[L[q]])++cnt;
                L[q]=R[q]=-1;
                if(R[q]==nxt[q])++cnt;
            };
            auto insert_front=[&](int q)
            {
                if(R[q]==nxt[q])--cnt;
                L[q]=0;
                R[q]=R[0];
                L[R[0]]=q;
                R[0]=q;
                if(R[q]==nxt[q])++cnt;
            };
            if(L[p]==-1)
            {
                if(now==m)Del(L[0]);
                else ++now;
                insert_front(p);
            }
            else
            {
                Del(p);
                insert_front(p);
            }
            if(cnt==n)End("Yes");
        }
        End("No");
    }
    void solve()
    {
        n=rd(),q=rd();
        for(int i=1;i<=n;++i)A[i]=rd();
        while(q--)Solve();
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
