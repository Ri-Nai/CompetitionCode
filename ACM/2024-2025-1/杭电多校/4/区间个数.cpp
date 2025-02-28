#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
bool Nai;
int rd()
{
    int res = 0, f = 1;
    char c;
    do
        (c = getchar()) == '-' && (f = -1);
    while (!isdigit(c));
    while (isdigit(c))
        res = (c ^ 48) + (res << 1) + (res << 3), c = getchar();
    return res * f;
}
namespace T
{
    typedef long long ll;
    template <class T>
    constexpr T power(T a, ll b)
    {
        T res{1};
        for (; b; b /= 2, a *= a)
            if (b % 2)
                res *= a;
        return res;
    }

    constexpr ll mul(ll a, ll b, ll p)
    {
        ll res = a * b - ll(1.L * a * b / p) * p;
        res %= p;
        if (res < 0)
            res += p;
        return res;
    }

    template <ll P>
    struct MInt
    {
        ll x;
        constexpr MInt() : x{0} {}
        constexpr MInt(ll x) : x{norm(x % getMod())} {}

        static ll Mod;
        constexpr static ll getMod()
        {
            if (P > 0)
                return P;
            else
                return Mod;
        }
        constexpr static void setMod(ll Mod_)
        {
            Mod = Mod_;
        }
        constexpr ll norm(ll x) const
        {
            if (x < 0)
                x += getMod();
            if (x >= getMod())
                x -= getMod();
            return x;
        }
        constexpr ll val() const
        {
            return x;
        }
        constexpr MInt operator-() const
        {
            MInt res;
            res.x = norm(getMod() - x);
            return res;
        }
        constexpr MInt inv() const
        {
            return power(*this, getMod() - 2);
        }
        constexpr MInt &operator*=(MInt rhs) &
        {
            if (getMod() < (1ULL << 31))
                x = x * rhs.x % int(getMod());
            else
                x = mul(x, rhs.x, getMod());
            return *this;
        }
        constexpr MInt &operator+=(MInt rhs) &
        {
            x = norm(x + rhs.x);
            return *this;
        }
        constexpr MInt &operator-=(MInt rhs) &
        {
            x = norm(x - rhs.x);
            return *this;
        }
        constexpr MInt &operator/=(MInt rhs) &
        {
            return *this *= rhs.inv();
        }
        friend constexpr MInt operator*(MInt lhs, MInt rhs)
        {
            MInt res = lhs;
            res *= rhs;
            return res;
        }
        friend constexpr MInt operator+(MInt lhs, MInt rhs)
        {
            MInt res = lhs;
            res += rhs;
            return res;
        }
        friend constexpr MInt operator-(MInt lhs, MInt rhs)
        {
            MInt res = lhs;
            res -= rhs;
            return res;
        }
        friend constexpr MInt operator/(MInt lhs, MInt rhs)
        {
            MInt res = lhs;
            res /= rhs;
            return res;
        }
        friend constexpr std::istream &operator>>(std::istream &is, MInt &a)
        {
            ll v;
            is >> v;
            a = MInt(v);
            return is;
        }
        friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a)
        {
            return os << a.val();
        }
        friend constexpr bool operator==(MInt lhs, MInt rhs)
        {
            return lhs.val() == rhs.val();
        }
        friend constexpr bool operator!=(MInt lhs, MInt rhs)
        {
            return lhs.val() != rhs.val();
        }
        friend constexpr bool operator<(MInt lhs, MInt rhs)
        {
            return lhs.val() < rhs.val();
        }
    };

    template <>
    ll MInt<0>::Mod = 998244353;

    constexpr int P = 998244353;
    using Z = MInt<P>;
    const int M = 1.5e7 + 5;
    Z fac[M], inv[M];
    Z Com(int n, int m)
    {
        if (n < 0)
            return 0;
        if (m < 0)
            return 0;
        if (n - m < 0)
            return 0;
        Z res = fac[n] * inv[m];
        res *= inv[n - m];
        return res;
    }
    void init()
    {
        fac[0] = 1;
        for (int i = 1; i < M; ++i)
            fac[i] = i * fac[i - 1];
        inv[M - 1] = 1 / fac[M - 1];
        for (int i = M - 2; i >= 0; --i)
            inv[i] = (i + 1) * inv[i + 1];
    }
    void solve()
    {
        int n, k;
        cin >> n >> k;
        Z ans = 0;
        if (k == 0)
            ans += fac[n] * n;
        for (int i = 2; i <= n; ++i)
        {
            int lcnt = n - k - i + 1;
            int has = i - 2 + k;
            // cout << lcnt << ' ' << has << '\n' ;
            ans += max(n - i + 1, 0) * max(lcnt, 0) * Com(has, i - 2) * fac[i] * fac[n - i];
        }
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    T::init();
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
