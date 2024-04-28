#include<cstdio>
inline int min(const int &a,const int &b){return a<b?a:b;}
int main()
{
    int a,b,d,c,res;
    scanf("%d%d%d%d",&a,&b,&d,&c);
    if(!d&&!c)res=0;
    else if(!d)res=min(c,b);
    else if(!c)res=min(d,a);
    else if(a>b)res=b+min((b+1)*d,a);
    else res=a+min((a+1)*c,b);
    printf("%d\n",res);
}