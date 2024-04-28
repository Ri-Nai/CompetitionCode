#include<bits/stdc++.h>
#define ULL unsigned long long
const int N=1e6+5,base=19260817;
char s[N],tmp[2];
ULL Hash1[N],Hash2[N],Base[N];
ULL Hash_1(int l,int r)
{
    return Hash1[r]-Hash1[l-1]*Base[r-l+1];
}
ULL Hash_2(int l,int r)
{
    return Hash2[l]-Hash2[r+1]*Base[r-l+1];
}
bool check(int L,int R)
{
    int l=1,r=R-L>>1,mid,ans=1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(Hash_1(L,L+mid)==Hash_2(R-mid,R))l=mid+1;
        else ans=mid,r=mid-1; 
    }
    return s[L+ans]<s[R-ans];
}
int main()
{
    int n;scanf("%d", &n);
    int l=1,r=n,num=0;Base[0]=1;
    for(int i=1;i<=n;++i)scanf("%s",tmp),s[i]=tmp[0];
    for(int i=1;i<=n;++i)Hash1[i]=Hash1[i-1]*base+s[i];
    for(int i=n;i>=1;--i)Hash2[i]=Hash2[i+1]*base+s[i];
    for(int i=1;i<=n;++i)Base[i]=Base[i-1]*base;
    while(l<=r)
    {
        if(s[l]<s[r])putchar(s[l++]);
        else if(s[l]>s[r])putchar(s[r--]);
        else if(check(l,r))putchar(s[l++]);
        else putchar(s[r--]);
        if(++num%80==0)putchar('\n');
    }
}   