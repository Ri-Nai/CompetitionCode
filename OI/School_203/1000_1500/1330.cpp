#include<cstdio>
#include<algorithm>
int main()
{
    int a,b,x,y,p;
    scanf("%d%d%d%d",&a,&x,&b,&y);
    p=std::__gcd(x,y);
    printf("%d\n",std::min(p-std::abs(a-b)%p,std::abs(a-b)%p));
}