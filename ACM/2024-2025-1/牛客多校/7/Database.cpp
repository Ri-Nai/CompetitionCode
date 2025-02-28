#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#endif
using namespace std;
typedef unsigned long long ull;
struct STRING
{
    ull Hash;
    string T;

    STRING() : Hash(0) {} // Initialize Hash to 0

    STRING(string s) : T(s), Hash(0)
    {
        for (auto c : s)
            Hash = Hash * 19260817 + c; // Compute Hash
    }

    bool operator<(const STRING &S) const
    {
        if (Hash != S.Hash)
            return Hash < S.Hash;
        return T < S.T;
    }

    bool operator==(const STRING &S) const
    {
        return Hash == S.Hash;
    }

    friend ostream &operator<<(ostream &os, const STRING &S)
    { // Pass by const reference
        os << S.T;
        return os;
    }
    void show()
    {
        for (char c : T)
            putchar(c);
        puts("");
    }
};
struct Database
{
    vector<STRING> field_names;
    vector<pair<int, map<STRING, STRING>>> table;
    vector<pair<int, map<STRING, STRING>>> current_transaction;
    vector<pair<int, map<STRING, STRING>>> deleted_rows;
    bool in_transaction = 0;
    int insert_order = 0;
    Database(const vector<STRING> &fields) : field_names(fields) {}
    void begin()
    {
        in_transaction = true;
        current_transaction.clear();
        deleted_rows.clear();
    }
    void commit()
    {
        for (const auto &row : current_transaction)
            table.push_back(row);
        in_transaction = false;
        current_transaction.clear();
        deleted_rows.clear();
    }
    void abort()
    {

        for (const auto &row : deleted_rows)
            table.push_back(row);
        in_transaction = false;
        current_transaction.clear();
        deleted_rows.clear();
    }
    void insert(const vector<STRING> &values)
    {
        map<STRING, STRING> new_row;
        for (size_t i = 0; i < values.size(); ++i)
            new_row[field_names[i]] = values[i];
        if (in_transaction)
            current_transaction.push_back({insert_order++, new_row});
        else
            table.push_back({insert_order++, new_row});
    }
    vector<STRING> select(const STRING &output_field, const STRING &condition_field, const STRING &condition_value)
    {
        vector<pair<int, STRING>> result;
        for (const auto &entry : table)
        {
            const auto &row = entry.second;
            if (row.at(condition_field) == condition_value)
            {
                result.emplace_back(entry.first, row.at(output_field));
            }
        }
        if (in_transaction)
        {
            for (const auto &entry : current_transaction)
            {
                const auto &row = entry.second;
                if (row.at(condition_field) == condition_value)
                    result.emplace_back(entry.first, row.at(output_field));
            }
        }
        sort(result.begin(), result.end());
        vector<STRING> answer;
        for (auto [x, y] : result)
            answer.push_back(y);
        return answer;
    }
    vector<STRING> select_in(const STRING &output_field, const STRING &condition_field, const vector<STRING> &condition_values_vector)
    {
        vector<pair<int, STRING>> result;
        set<STRING> condition_values;
        for (auto s : condition_values_vector)
            condition_values.insert(s);
        for (const auto &entry : table)
        {
            const auto &row = entry.second;
            if (condition_values.count(row.at(condition_field)))
                result.emplace_back(entry.first, row.at(output_field));
        }
        if (in_transaction)
        {
            for (const auto &entry : current_transaction)
            {
                const auto &row = entry.second;
                if (condition_values.count(row.at(condition_field)))
                    result.emplace_back(entry.first, row.at(output_field));
            }
        }
        sort(result.begin(), result.end());
        vector<STRING> answer;
        for (auto [x, y] : result)
            answer.push_back(y);
        return answer;
    }
    int delete_records(const STRING &condition_field, const STRING &condition_value)
    {
        int count = 0;
        auto new_end = remove_if(table.begin(), table.end(), [&](const auto &entry)
                                 {
            const auto &row = entry.second;
            if (row.at(condition_field) == condition_value) {
                if (in_transaction) {
                    deleted_rows.push_back(entry);
                }
                count++;
                return true;
            }
            return false; });
        table.erase(new_end, table.end());
        if (in_transaction)
        {
            auto new_end_tx = remove_if(current_transaction.begin(), current_transaction.end(), [&](const auto &entry)
                                        {
                const auto &row = entry.second;
                return row.at(condition_field) == condition_value; });
            count += distance(new_end_tx, current_transaction.end());
            current_transaction.erase(new_end_tx, current_transaction.end());
        }
        return count;
    }
    int delete_in(const STRING &condition_field, const vector<STRING> &condition_values_vector)
    {
        int count = 0;
        set<STRING> condition_values;
        for (auto s : condition_values_vector)
            condition_values.insert(s);
        auto new_end = remove_if(table.begin(), table.end(), [&](const auto &entry)
                                 {
            const auto &row = entry.second;
            if (condition_values.count(row.at(condition_field))) {
                if (in_transaction) {
                    deleted_rows.push_back(entry);
                }
                count++;
                return true;
            }
            return false; });
        table.erase(new_end, table.end());

        if (in_transaction)
        {
            auto new_end_tx = remove_if(current_transaction.begin(), current_transaction.end(), [&](const auto &entry)
                                        {
                const auto &row = entry.second;
                return condition_values.count(row.at(condition_field)); });
            count += distance(new_end_tx, current_transaction.end());
            current_transaction.erase(new_end_tx, current_transaction.end());
        }
        return count;
    }
};
vector<string> split(const string &s, char delimiter, int cnt = 11451419)
{
    vector<string> tokens;
    int start = 0;
    int end = s.find(delimiter);
    int now = 1;
    while (now < cnt && end != string::npos)
    {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find(delimiter, start);
        ++now;
    }
    tokens.push_back(s.substr(start));
    return tokens;
}
inline string Substr(string s, int l, int r)
{
    return s.substr(l, r - l);
}
char TMP[5005];
string read()
{
    scanf("%s", TMP);
    return string(TMP);
}
int main()
{
    // ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<string> names;
    auto CHANGE = [&](vector<string> v) -> vector<STRING>
    {
        vector<STRING> V;
        for (auto s : v)
            V.emplace_back(s);
        return V;
    };
    for (int i = 0; i < n; ++i)
        names.push_back(read());
    Database DB(CHANGE(names));
    function<vector<STRING>(string)> PARSE;
    function<vector<STRING>(string)> SELECT;
    function<vector<STRING>(string)> SELECT_IN;
    auto show = [&](auto v)
    {
        printf("%d\n", v.size());
        if (!v.empty())
        {
            v[0].show();
            v[(v.size() - 1) >> 1].show();
            v.back().show();
        }
    };
    PARSE = [&](string s) -> vector<STRING>
    {
        if (s.back() == ')')
        {
            if (s[9] == '(')
                return SELECT_IN(Substr(s, 10, s.size() - 1));
            return SELECT(Substr(s, 7, s.size() - 1));
        }
        return CHANGE(split(s, ','));
    };
    SELECT = [&](string s) -> vector<STRING>
    {
        vector<string> args = split(s, ',', 3);
        return DB.select(args[0], args[1], args[2]);
    };
    SELECT_IN = [&](string s) -> vector<STRING>
    {
        vector<string> args = split(s, ',', 3);
        return DB.select_in(args[0], args[1], PARSE(args[2]));
    };
    auto DELETE = [&](string s)
    {
        vector<string> args = split(s, ',', 2);
        return DB.delete_records(args[0], args[1]);
    };
    auto DELETE_IN = [&](string s)
    {
        vector<string> args = split(s, ',', 2);
        return DB.delete_in(args[0], PARSE(args[1]));
    };
    for (int i = 1; i <= q; ++i)
    {
        string command = read();
        if (command[0] == 'b')
            DB.begin();
        else if (command[0] == 'c')
            DB.commit();
        else if (command[0] == 'a')
            DB.abort();
        else if (command[0] == 'i')
        {
            string item = Substr(command, 7, command.size() - 1);
            auto items = CHANGE(split(item, ','));
            DB.insert(items);
        }
        else if (command[0] == 's' && command[6] == '(')
            show(SELECT(Substr(command, 7, command.size() - 1)));
        else if (command[0] == 's' && command[9] == '(')
            show(SELECT_IN(Substr(command, 10, command.size() - 1)));
        else if (command[0] == 'd' && command[6] == '(')
            printf("%d\n", DELETE(Substr(command, 7, command.size() - 1)));
        else
            printf("%d\n", DELETE_IN(Substr(command, 10, command.size() - 1)));
    }
}
