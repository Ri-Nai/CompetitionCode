#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int mn=1e9+5;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        mn=min(mn,abs(x));
    }
    cout<<mn<<endl;
}
