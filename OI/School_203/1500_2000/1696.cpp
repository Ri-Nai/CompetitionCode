#include<bits/stdc++.h>
using namespace std;
char s1[20][20]={"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char s2[20][20]={"ten","eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char s3[20][20]={"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
char s4[20][20]={"","onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred"};
string s[1005];
char tmp[1005];
int len,flag,n;
string GetS(int num)
{
	if(num==1000)return "onethousand";
	if(num<10)return s1[num];
	if(num<20)return s2[num-10];
	if(num<100&&num%10==0)return s3[num/10];
	if(num%100==0)return s4[num/100];
	if(num>100)return GetS(num/100*100)+GetS(num%100);
	if(num>10)return GetS(num/10*10)+GetS(num%10);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",tmp);
		s[i]=tmp;
		if(tmp[0]^'$')len+=s[i].size();
		else flag=i;
	}
	for(int i=1;i<=1000;++i)
	{
		string tmp=GetS(i);
		if(len+tmp.size()==i)
		{
			s[flag]=tmp;
			break;
		}
	}
	for(int i=1;i<=n;++i)
	{
		cout<<s[i]<<'\n';
	}
}