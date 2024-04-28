#include<bits/stdc++.h>
using namespace std;
double p;
long long a,b,ans[6],now=1;
char s[20];
int main()
{
	scanf("%lld.%s",&a,s+1);
	int len=strlen(s+1),id=1;
	while(len>=1&&s[len]=='0')--len;
	while(id<=len&&s[id]=='0')++id,a*=10,now*=10;
	while(id<=len)b=b*10+(s[id]-48),++id,a*=10,now*=10;
	long long num=a+b;
	//printf("%lld %lld\n",num,now);
	while(b&&!(now%5)&&!(num%5)&&!(b%5))num/=5,b/=5,now/=5;
	while(b&&!(now%2)&&!(num%2)&&!(b%2))num/=2,b/=2,now/=2;
	//printf("%lld %lld\n",num,now);
	//printf("%lld %lld\n",num,now);
	for(int i=5;i>=2;--i)
    {
        ans[i]=(num-now)/(i-1);
        num-=ans[i]*i;
        now-=ans[i];
    }
    ans[1]=now;
    for(int i=1;i<=5;++i)
    	printf("%lld ",ans[i]);
}