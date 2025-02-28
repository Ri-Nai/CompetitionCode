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
    class Frac
    {
    private:
        ll numerator;
        ll denominator;

    public:
        Frac();
        Frac(double dec);
        template <typename number>
        Frac(number num, number den = 1);

        ll Get_Numerator() const;
        ll Get_Denominator() const;

        Frac operator+(const Frac &other) const;
        Frac operator-(const Frac &other) const;
        Frac operator/(const Frac &other) const;
        Frac operator*(const Frac &other) const;
        Frac operator*(const int &p) const;
        Frac operator-() const;

        bool operator<(const Frac &other) const;
        bool operator>(const Frac &other) const;
        bool operator<=(const Frac &other) const;
        bool operator>=(const Frac &other) const;
        bool operator==(const Frac &other) const;
        bool operator!=(const Frac &other) const;

        std::string Format_Output(const int &place) const;
        friend std::istream &operator>>(std::istream &is, Frac &frac);
        friend std::ostream &operator<<(std::ostream &os, const Frac &frac);
        friend Frac operator*(const int &p, const Frac &frac);
    };
    /*
     * @Author: Reina__
     * @Date: 2024-04-18 13:43:55
     * @Last Modified by: Reina__
     * @Last Modified time: 2024-04-18 21:54:43
     */
    Frac::Frac()
    {
        numerator = 0;
        denominator = 1;
    }
    Frac::Frac(double dec)
    {
        int base = 1e6;
        int num = round(dec * base);
        *this = Frac(num, base);
    }
    template <typename number>
    Frac::Frac(number num, number den)
    {
        if (den < 0)
            den = -den, num = -num;
        numerator = num;
        denominator = den;
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    ll Frac::Get_Numerator() const
    {
        return numerator;
    }

    ll Frac::Get_Denominator() const
    {
        return denominator;
    }

    Frac Frac::operator+(const Frac &other) const
    {
        ll newNumerator = numerator * other.denominator + other.numerator * denominator;
        ll newDenominator = denominator * other.denominator;
        return Frac(newNumerator, newDenominator);
    }

    Frac Frac::operator-(const Frac &other) const
    {
        ll newNumerator = numerator * other.denominator - other.numerator * denominator;
        ll newDenominator = denominator * other.denominator;
        return Frac(newNumerator, newDenominator);
    }

    Frac Frac::operator*(const Frac &other) const
    {
        ll newNumerator = numerator * other.numerator;
        ll newDenominator = denominator * other.denominator;
        return Frac(newNumerator, newDenominator);
    }

    Frac Frac::operator/(const Frac &other) const
    {
        ll newNumerator = numerator * other.denominator;
        ll newDenominator = denominator * other.numerator;
        return Frac(newNumerator, newDenominator);
    }

    Frac Frac::operator*(const int &p) const
    {
        return Frac(numerator * p, denominator);
    }

    Frac operator*(const int &p, const Frac &frac)
    {
        return frac * p;
    }

    Frac Frac::operator-() const
    {
        return Frac(-numerator, denominator);
    }

    bool Frac::operator<(const Frac &other) const
    {
        return numerator * other.denominator - other.numerator * denominator < 0;
    }
    bool Frac::operator>(const Frac &other) const
    {
        return other < *this;
    }
    bool Frac::operator<=(const Frac &other) const
    {
        return !(*this > other);
    }
    bool Frac::operator>=(const Frac &other) const
    {
        return !(*this < other);
    }
    bool Frac::operator==(const Frac &other) const
    {
        return *this >= other && *this <= other;
    }
    bool Frac::operator!=(const Frac &other) const
    {
        return !(*this == other);
    }

    Frac abs(const Frac &frac)
    {
        if (frac.Get_Numerator() < 0)
            return Frac(-frac.Get_Numerator(), -frac.Get_Denominator());
        return frac;
    }
    // 使分数比较格式化地输出
    // 由于难以调教std::format,自己写了一个很丑陋的
    std::string Frac::Format_Output(const int &place) const
    {
        std::stringstream ss;
        std::string result = "";
        ss << *this;
        ss >> result;
        int length = result.size();
        if (length >= place)
            return " " + result + " ";
        int rest = place - length;
        int middle = rest / 2;
        result = std::string(middle, ' ') + result + std::string(rest - middle, ' ');
        return result;
    }

    std::ostream &operator<<(std::ostream &os, const Frac &frac)
    {
        if (frac.denominator == 1)
            os << frac.numerator;
        else if (frac.numerator == 0)
            os << 0;
        else
            os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    std::istream &operator>>(std::istream &is, Frac &frac)
    {
        std::string input;
        is >> input;

        // 将输入字符串解析为分子和分母
        std::istringstream iss(input);
        char slash;
        int num, den;
        if (iss >> num >> slash >> den && slash == '/')
        {
            frac = Frac(num, den);
            // 成功解析为分数
            // Ciallo～(∠・ω< )⌒★
        }
        else
        {
            double decimal;
            iss.clear();
            iss.seekg(0);
            // 解析为小数
            if (iss >> decimal)
            {
                frac = Frac(decimal);
            }
            else
            {
                // 解析无法解析成数值返回错误
                frac = Frac(0);
                is.setstate(std::ios::failbit);
            }
        }

        return is;
    }

    void solve()
    {
        int n = rd(), m = rd();
        vector<int> in(n + 1), sz(n + 1);
        vector<vector<int>> E(n + 1);
        queue<int> Q;
        for (int i = 1; i <= n; ++i)
        {
            sz[i] = rd();
            for (int j = 1; j <= sz[i]; ++j)
            {
                int v = rd();
                ++in[v];
                E[i].push_back(v);
            }
        }
        vector<Frac> ans(n + 1); // 自己写个分数类
        for (int i = 1; i <= m; ++i)
        {
            Q.push(i);
            ans[i] = 1;
        }
        while (!Q.empty())
        {
            int u = Q.front();
            if (sz[u] != 0)
                ans[u] = ans[u] / sz[u];
            Q.pop();
            for (int v : E[u])
            {
                ans[v] = ans[v] + ans[u];
                if (!--in[v])
                    Q.push(v);
            }
        }
        for (int i = m + 1; i <= n; ++i)
            if (sz[i] == 0)
                cout << ans[i].Get_Numerator() << ' '
                     << ans[i].Get_Denominator() << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
