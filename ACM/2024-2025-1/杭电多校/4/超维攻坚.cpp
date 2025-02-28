#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=(j);i<=(k);++i)
#define dow(i,j,k) for(i=(j);i>=(k);--i)
const int N=20;
struct P{
    int x,y,z;
}p[N];
int n,flg[N];
P cross(P v,P u){
    int a=u.x,b=u.y,c=u.z,d=v.x,e=v.y,f=v.z;
    return (P){b*f-e*c,c*d-a*f,a*e-b*d};
}
int dot(P v,P u){
    return v.x*u.x+v.y*u.y+v.z*u.z;
}
bool ck(int s){
    vector<P>check;
    int i,j,k;
    int cnt=0;rep(i,1,n)if((1<<i-1)&s)++cnt;if(cnt<=1)return 1;
    if(cnt==2){
        rep(i,1,n)if((1<<i-1)&s)break;
        dow(j,n,1)if((1<<j-1)&s)break;
        P vv=(P){p[j].x-p[i].x,p[j].y-p[i].y,p[j].z-p[i].z};
        int flg=1;
        rep(k,1,n)if(((1<<k-1)&s)==0){
            P uu=(P){p[k].x-p[i].x,p[k].y-p[i].y,p[k].z-p[i].z};
            P ret=cross(vv,uu);
            if(ret.x==0 && ret.y==0 && ret.z==0){
                int mnx=min(p[i].x,p[j].x),mxx=max(p[i].x,p[j].x);
                if(mnx<=p[k].x && p[k].x<=mxx){
                    flg=0;
                }
            }
        }
        return flg;
    }
    rep(i,1,n)if((1<<i-1)&s)rep(j,i+1,n)if((1<<j-1)&s){
        check.push_back((P){p[j].x-p[i].x,p[j].y-p[i].y,p[j].z-p[i].z});
    }
    rep(i,1,n)if((1<<i-1)&s)rep(j,i+1,n)if((1<<j-1)&s)rep(k,j+1,n)if((1<<k-1)&s){
        P v1=(P){p[j].x-p[i].x,p[j].y-p[i].y,p[j].z-p[i].z};
        P v2=(P){p[k].x-p[i].x,p[k].y-p[i].y,p[k].z-p[i].z};
        check.push_back(cross(v1,v2));
    }
    rep(i,1,n)flg[i]=0;
    for(auto v:check){
        int mn=1<<30,mx=1<<31;
        rep(i,1,n)if((1<<i-1)&s){
            int val=dot(v,p[i]);
            mn=min(mn,val);mx=max(mx,val);
        }
        rep(i,1,n)if(((1<<i-1)&s)==0){
            int val=dot(v,p[i]);
            if(val<mn || val>mx)flg[i]=1;
        }
    }
    bool ret=1;
    rep(i,1,n)if(((1<<i-1)&s)==0){
        if(flg[i]==0)ret=0;
    }
    return ret;
}
int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int T,i,j,s;cin>>T;
    while(T--){
        cin>>n;
        rep(i,1,n)cin>>p[i].x>>p[i].y>>p[i].z;
        int ans=0;
        rep(s,1,(1<<n)-1){
            if(ck(s))++ans;
        }
        cout<<ans<<"\n";
    }
}
