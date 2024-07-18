#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int X = rand() % 10;
    int Y = rand() % 10;
    int n = rand() % 50 + 1;
    int q = rand() % 10 + 10;
    cout << X  << ' ' << Y << " " << n << " " << q << '\n';
    for (int i = 0; i < n; ++i)
    {
        cout << "URDL"[rand()%4] << " " << rand() % 10 + 2 << "\n";
    }
    for (int i = 0; i < q; ++i)
    {
        cout << rand() % (X + 1) << " " << rand() % (Y + 1) << ' ';
        int l = rand() % n + 1;
        int r = rand() % n + 1;
        if (r < l)
            swap(l, r);
        cout << l << ' ' << r << '\n';
    }
}
