#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=205;
    int k;
    int A[N*N];
    bool check(int p,int a,int b)
    {
        cout<<(p?"r":"c")<<' '<<a<<' '<<b<<'\n';
        cout.flush();
        string s;
        cin>>s;
        return s=="yes";
    }
    void solve()
    {
        cin>>k;
        for(int i=1;i<=k;++i)
            cin>>A[i];
        sort(A+1,A+k+1);
        vector<int>first;
        first.push_back(1);
        for(int i=2;i<=k;++i)
            if(check(1,A[first.back()],A[i]))first.push_back(i);
        if(first.size()==1)cout<<"! "<<A[1]<<'\n';
        else
        {
            int n=first.size();
            int m=(k-1)/n;
            first.push_back(k+1);
            int t=0;
            for(int i=0;i<n;++i)
                if(first[i+1]-first[i]!=m)
                {
                    t=i;
                    break;
                }
            int last=A[first[t]];
            set<int>S;
            for(int i=first[t]+1;i<first[t+1];++i)
                S.insert(A[i]);
            while(S.size()>1)
            {
                int y=-1;
                for(int x:S)
                    if(check(0,last,x)){y=x;break;}
                last=y;
                S.erase(y);
            }
            cout<<"! "<<*S.begin()<<'\n';
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
