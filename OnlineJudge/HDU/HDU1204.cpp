#include<cmath>
#include<cstdio>
double p,q,ans,k;
int n,m;
int main()
{
    while(~scanf("%d%d%lf%lf",&n,&m,&p,&q))
    {
        if(n==0)puts("0.00");
        else if(m==0)puts("1.00");
        else if(p==0||q==1)puts("0.00");
        else if(p==1||q==0)puts("1.00");
        else if(p==q)printf("%.2lf\n",1.0*n/(n+m));
        else
        {
            k=q*(1-p)/(p*(1-q)),
            ans=(1.0-pow(k,n))/(1.0-pow(k,n+m));
            printf("%.2lf\n",ans);
        }
    }

}