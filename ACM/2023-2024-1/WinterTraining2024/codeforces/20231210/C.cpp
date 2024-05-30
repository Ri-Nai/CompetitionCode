#include<bits/stdc++.h>
using namespace std;
int Ceil(long long a,long long b)
{
    if(a%b==0)return a/b;
    return a/b+1;
}
int main()
{
    ios::sync_with_stdio(0);
    long long a,b,c;
    cin>>a>>b>>c;
    bool flag=0;
    for(int i=1;;++i)
    {
        string s;
        cin>>s;
        if(s[0]=='e')return 0;
        if(a<=2*c)cout<<"airline\n";
        else
        {
            // if(!flag and b<=i*a)
            if(!flag and i>=Ceil((b+c-a),a))flag=1,cout<<"buy"<<'\n';
            else if(flag)cout<<"self"<<'\n';
            else cout<<"airline\n";
        }
        cout.flush();
    }
}
/*
为什么呢
比如说
b-a+c<=ap;
(b+c-a)/a
我们肯定是希望
这个p越小越好嘛
b<=ax
b/a


*/
