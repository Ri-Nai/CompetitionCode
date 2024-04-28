#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,ans;
multiset<int>Q[N];
int main()
{
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;++i)
        scanf("%d%d",&x,&y),Q[x].insert(y);
    scanf("%d",&m);
    for(int x,y,r;m--;)
    {
        scanf("%d%d%d",&x,&y,&r);
        for(int j=max(-x,-r);j<=r;++j)
        {
            int l=sqrt(r*r-j*j),p=j+x;
            if(p>=N)break;
            multiset<int>::iterator it=Q[p].lower_bound(y-l);
            for(;it!=Q[p].end()&&*it<=y+l;)
                Q[p].erase(it++),++ans;
        }
    }
    printf("%d\n",n-ans);
}