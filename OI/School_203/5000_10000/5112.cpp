#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+5;
int cnt1[maxn],cnt2[maxn],len,n,k,A[maxn],B[maxn];
LL sum1[maxn],sum2[maxn],ans=1e18;
void Add1(int id,int x,int y)
{
    for(int i=id;i<=len;i+=i&-i)
        sum1[i]+=x,cnt1[i]+=y;
}
void Add2(int id,int x,int y)
{
    for(int i=id;i;i^=i&-i)
        sum2[i]+=x,cnt2[i]+=y;
}
pair<LL,int> Sum1(int id)
{
    LL res=0;int cnt=0;
    for(int i=id;i;i^=i&-i)
        res+=sum1[i],cnt+=cnt1[i];
    return make_pair(res,cnt);
}
pair<LL,int> Sum2(int id)
{
    LL res=0;int cnt=0;
    for(int i=id;i<=len;i+=i&-i)
        res+=sum2[i],cnt+=cnt2[i];
    return make_pair(res,cnt);
}
int check(int t)
{
    return Sum2(t).second-Sum1(t-1).second;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i];
    sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;
    for(int i=1;i<=n;++i)A[i]=lower_bound(B+1,B+len+1,A[i])-B;
    for(int i=1;i<k;++i)
        Add1(A[i],B[A[i]],1),
        Add2(A[i],B[A[i]],1);
    for(int i=k;i<=n;++i)
    {
        Add1(A[i],B[A[i]],1);
        Add2(A[i],B[A[i]],1);
        if(i>k)
        {
            Add1(A[i-k],-B[A[i-k]],-1);
            Add2(A[i-k],-B[A[i-k]],-1);
        }
        int l=1,r=len,res;
        while(l<=r)
        {
            int mid=l+r>>1;
            int tmp=check(mid);
            if((!(k&1)&&tmp>=0)||((k&1)&&tmp>0))
                res=mid,l=mid+1;
            else r=mid-1;
        }
        pair<LL,int>res1=Sum1(res-1),res2=Sum2(res+1);
        LL sm1=res1.first,sm2=res2.first;
        int ct1=res1.second,ct2=res2.second;
        ans=min(1ll*ct1*B[res]-sm1+sm2-1ll*ct2*B[res],ans);
    }
    printf("%lld\n",ans);
}