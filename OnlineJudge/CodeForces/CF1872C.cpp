#include<bits/stdc++.h>
using namespace std;
const int M=1e7+5;
int p[M],pr[M],len;
void init()
{
    for(int i=2;i<M;++i)
        if(!p[i])
        {
            pr[++len]=i;
            for(int j=i+i;j<M;j+=i)
                p[j]=i;
        }

}
namespace T
{
    void solve()
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l==r)
        {
            if(!p[l])puts("-1");
            else printf("%d %d\n",p[l],l-p[l]);
        }
        else if(l>=1 and r<=3)puts("-1");
        else
        {
            if(r%2)printf("%d %d\n",2,r-1-2);
            else printf("%d %d\n",2,r-2);
        }
    }
}
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)T::solve();
}
