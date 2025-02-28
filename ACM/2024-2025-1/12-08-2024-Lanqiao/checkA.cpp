#include <bits/stdc++.h>
using namespace std;

int RAND()
{
    return 1ll * rand() * rand() * rand() % (1000000000);
}
int main()
{
    do
    {
        system("dataA > D.in");
        system("D < D.in > 1.out");
        system("python D.py < D.in > 2.out");
    } while(!system("fc 1.out 2.out"));
}
/*
sigma sz * w
*/
