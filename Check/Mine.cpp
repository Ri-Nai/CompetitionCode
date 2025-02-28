#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<=k;++i)
#define dow(i,j,k) for(i=j;i>=k;--i)
#define pr pair
#define mkp make_pair
#define fi first
#define se second
const int N=1e5+10;
#define LL long long
const LL inf=1e17;
LL k[N],b[N],dp[N][2];
int seg[N<<2],n,K,f[N],g[N];
LL val(int x,LL day){return x!=0 ? day*k[x]+b[x]:-inf;}
void build(){
    int i;
    rep(i,1,K<<2)seg[i]=0;
}
void ins(int rt,int l,int r,int id){
    if(!seg[rt]){
        seg[rt]=id;return;
    }
    LL l1=val(seg[rt],l),l2=val(id,l);
    LL r1=val(seg[rt],r),r2=val(id,r);
    if(l2>=l1 && r2>=r1){seg[rt]=id;return;}
    if(l2<=l1 && r2<r1)return;
    int mid=l+r>>1;
    double its=(double)(b[seg[rt]]-b[id])/(double)(k[id]-k[seg[rt]]);
    if(its<=(double)mid){
        if(r2>=r1){ins(rt<<1,l,mid,seg[rt]);seg[rt]=id;}
        else ins(rt<<1,l,mid,id);
    }else{
        if(l2>=l1){ins(rt<<1|1,mid+1,r,seg[rt]);seg[rt]=id;}
        else ins(rt<<1|1,mid+1,r,id);
    }
}
int query(int rt,int l,int r,int x){
    if(l==r)return seg[rt];
    int mid=l+r>>1;
    if(mid>=x){
        int r1=query(rt<<1,l,mid,x);
        if(val(r1,x)>val(seg[rt],x))return r1;return seg[rt];
    }else{
        int r2=query(rt<<1|1,mid+1,r,x);
        if(val(r2,x)>val(seg[rt],x))return r2;return seg[rt];
    }
}
vector<int>t[N];
int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int T,i,j;cin>>T;
    while(T--){
        cin>>n>>K;
        rep(i,1,n)cin>>b[i]>>k[i];
        build();
        rep(i,1,n)ins(1,1,K,i),t[i].clear();
        rep(i,1,K){
            f[i]=g[i]=0;
            f[i]=query(1,1,K,i);
            t[f[i]].push_back(i);
        }
        build();
        rep(i,1,n){
            for(auto v:t[i]){
                int r=query(1,1,K,v);
                if(val(r,v)>val(g[v],v))g[v]=r;
            }
            ins(1,1,K,i);
        }
        build();
        dow(i,n,1){
            for(auto v:t[i]){
                int r=query(1,1,K,v);
                if(val(r,v)>val(g[v],v))g[v]=r;
            }
            ins(1,1,K,i);
        }
        //rep(i,1,K)cerr<<f[i]<<' ';cerr<<'\n';
        //rep(i,1,K)cerr<<g[i]<<' ';cerr<<'\n';
        dp[1][1]=val(f[1],1);dp[1][0]=val(g[1],1);
        rep(i,2,K){
            dp[i][0]=dp[i][1]=-inf;
            if(g[i-1]^f[i])dp[i][1]=max(dp[i][1],dp[i-1][0]+val(f[i],i));
            if(f[i-1]^f[i])dp[i][1]=max(dp[i][1],dp[i-1][1]+val(f[i],i));
            if(g[i-1]^g[i])dp[i][0]=max(dp[i][0],dp[i-1][0]+val(g[i],i));
            if(f[i-1]^g[i])dp[i][0]=max(dp[i][0],dp[i-1][1]+val(g[i],i));
        }
        cout<<max(dp[K][0],dp[K][1])<<'\n';
    }
}
