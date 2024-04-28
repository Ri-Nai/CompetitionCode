#include<bits/stdc++.h>
using namespace std;
const int P=1e7+5;
bool p[P];
int Q,K,L,M,pr[P>>3],tot,ans[155][155];
void init()
{
    p[0]=p[1]=1;
    memset(ans,-1,sizeof(ans));
    for(int i=2;i<P;++i)
    {
        if(p[i])continue;
 		pr[++tot]=i;
   		for(int j=i+i;j<P;j+=i)p[j]=1;
    }
    for(int i=1;i<=tot;++i)
    {
        if(pr[i]<=150)continue;
        int cnt=0;
        for(int j=1;j<=150;++j)
        {
            if(!p[pr[i]+j-1])++cnt;
            if(ans[j][cnt]==-1)ans[j][cnt]=pr[i];
        }
    }
}
inline bool check(int t)
{
	if(!t)return 0;
	return t<=M||!p[t];
}
int main()
{
    for(init(),scanf("%d",&Q);Q--;)
    {
        scanf("%d%d%d",&K,&L,&M);
        int cnt=0,res=-1;
        for(int i=1;i<K;++i)cnt+=check(i);
        for(int i=K;i<=150+K-1;++i)
            if((cnt+=check(i)-check(i-K))==L&&(res=i-K+1))
            	break;
        if(res!=-1)printf("%d\n",res);
        else printf("%d\n",ans[K][L]);
    }
}