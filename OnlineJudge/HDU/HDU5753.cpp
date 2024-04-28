#include<cstdio>
int main()
{
    int n,x;
    double ans;
    while(~scanf("%d",&n))
    {
        ans=0;
        if(n==1)
            scanf("%d",&x),printf("%.6lf\n",1.0*x);
        else
        {
            for(int i=1;i<=n;++i)
            {
                scanf("%d",&x);
                if(i==1||i==n)ans+=x/2.0;
                else ans+=x/3.0;
            }
            printf("%.6lf\n",ans);
        }
    }
}
