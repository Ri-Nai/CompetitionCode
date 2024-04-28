#include<cstdio>
#include<cstring>
#include<algorithm>
int n,m,dp[255];
struct $
{
    int A,B;
    bool operator < ($ _){return B<_.B;}
}A[255];
void solve()
{
    memset(dp,0,sizeof dp);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&A[i].A);
    for(int i=1;i<=n;++i)scanf("%d",&A[i].B);
    std::sort(A+1,A+n+1);
    for(int i=1;i<=n;++i)
        for(int j=m;j>=1;--j)
            dp[j]=std::max(dp[j],dp[j-1]+A[i].A+A[i].B*(j-1));
    printf("%d\n",dp[m]);
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)solve();
}
#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
struct node{
    int a;//start
    int b;//add
    bool operator < (const node &A)const{
        return b<A.b;
    }
}tree[255];
int dp[255][255];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        scanf("%d",&tree[i].a);//at first
    for(int i=1;i<=n;++i)
        scanf("%d",&tree[i].b);//add
    sort(tree+1,tree+n+1);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i){
        for(int j=m;j>=1;--j){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+tree[i].a+tree[i].b*(j-1));
        }
    }
    cout<<dp[n][m]<<endl;
}
int main(){
    cin>>t;
    while(t--){
        solve();
    }
}
