#include<bits/stdc++.h>
using namespace std;
char s1[2],s2[2];
int main()
{
	cin>>s1>>s2;
	if(*s1=='Y')cout<<(char)toupper(*s2)<<endl;
	else cout<<(char)tolower(*s2)<<endl;
}
