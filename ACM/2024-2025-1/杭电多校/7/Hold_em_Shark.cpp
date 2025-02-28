#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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
using namespace std;

struct Card
{
    int rank;
    char suit;

    bool operator<(const Card &other) const
    {
        if (rank != other.rank)
            return rank > other.rank;
        return suit > other.suit;

    }
};

struct Hand
{
    int type;          // 表示手牌的类型（皇家同花顺等）
    vector<int> ranks; // 用于手牌的详细比较
    Hand() : type{}, ranks{} {}
    Hand(int _, vector<int> __) : type{_}, ranks{__} {}
    bool operator < (const Hand &h2) const
    {
        if (type != h2.type)
            return type < h2.type;
        return ranks < h2.ranks;
    }
    bool operator == (const Hand &h2) const
    {
        return type == h2.type && ranks == h2.ranks;
    }
};

// 扑克牌的点数映射
map<char, int> rank_map = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};
// 识别手牌的类型
Hand evaluate_hand(vector<Card> cards)
{
    sort(cards.begin(), cards.end());

    bool is_flush = true;
    bool is_straight = true;
    vector<int> ranks;
    map<int, int> rank_count;

    for (int i = 1; i < 5; ++i)
        if (cards[i].suit != cards[0].suit)
            is_flush = false;
    for (int i = 1; is_straight && i < 5; ++i)
    {
        if (i == 4 && cards[i].rank == 14 && cards[i - 1].rank == 5)
            ;
        else if (cards[i].rank != cards[i - 1].rank + 1)
            is_straight = false;
    }

    // 记录各个牌的点数
    for (int i = 0; i < 5; ++i)
    {
        ranks.push_back(cards[i].rank);
        rank_count[cards[i].rank]++;
    }
    vector<int> counts;
    for (auto [x, y] : rank_count)
        counts.push_back(y);
    sort(counts.begin(), counts.end());
    reverse(counts.begin(), counts.end());
    // 判断各种牌型
    if (is_straight && is_flush && ranks[4] == 14 && ranks[3] == 13)
        return {10, ranks}; // 皇家同花顺
    if (is_straight && is_flush)
        return {9, ranks}; // 同花顺
    if (counts[0] == 4)
        return {8, ranks}; // 四条
    if (counts[0] == 3 && counts[1] == 2)
        return {7, ranks}; // 葫芦
    if (is_flush)
        return {6, ranks}; // 同花
    if (is_straight)
        return {5, ranks}; // 顺子
    if (counts[0] == 3)
        return {4, ranks}; // 三条
    if (counts[0] == 2 && counts[1] == 2)
        return {3, ranks}; // 两对
    if (counts[0] == 2)
        return {2, ranks}; // 一对
    return {1, ranks}; // 散牌
}
Hand Best_Hands(vector<Card> cards)
{
    Hand MX;
    for (int i = 31; i < 128; ++i)
    {
        vector<Card> now;
        for (int j = 0; j < 7; ++j)
            if (1 << j & i)
                now.push_back(cards[j]);
        if (now.size() == 5)
            MX = max(MX, evaluate_hand(now));
    }
    return MX;
}
// 比较两个手牌大小
int calculate_wins(int target, const vector<vector<Card>> &capoo, const vector<Card> &table, const vector<Card> &remaining_cards)
{
    int wins = 0;
    vector<Card> full_table = table;
    for (auto it1 = remaining_cards.begin(); it1 != remaining_cards.end(); ++it1)
    {
        for (auto it2 = next(it1); it2 != remaining_cards.end(); ++it2)
        {
            full_table.push_back(*it1);
            full_table.push_back(*it2);
            vector<Card> target_cards = {capoo[target][0], capoo[target][1], full_table[0], full_table[1], full_table[2], full_table[3], full_table[4]};
            Hand target_hand = Best_Hands(target_cards);
            bool is_win = true;
            for (int i = 0; i < 4; ++i)
            {
                if (i == target)
                    continue;
                vector<Card> opponent_cards = {capoo[i][0], capoo[i][1], full_table[0], full_table[1], full_table[2], full_table[3], full_table[4]};
                Hand opponent_hand = Best_Hands(opponent_cards);
                if (target_hand < opponent_hand || target_hand == opponent_hand)
                {
                    is_win = false;
                    break;
                }
            }
            if (is_win)
                wins++;
            full_table.pop_back();
            full_table.pop_back();
        }
    }
    return wins;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        vector<Card> table(3);
        vector<vector<Card>> capoo(4, vector<Card>(2));
        set<Card> used_cards;
        for (int i = 0; i < 3; ++i)
        {
            string card;
            cin >> card;
            table[i] = {rank_map[card[0]], card[1]};
            used_cards.insert(table[i]);
        }
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                string card;
                cin >> card;
                capoo[i][j] = {rank_map[card[0]], card[1]};
                used_cards.insert(capoo[i][j]);
            }
        }

        int target_capoo;
        cin >> target_capoo;
        vector<Card> remaining_cards;
        for (int rank = 2; rank <= 14; ++rank)
        {
            for (char suit : {'H', 'D', 'C', 'S'})
            {
                Card card = {rank, suit};
                if (used_cards.find(card) == used_cards.end())
                    remaining_cards.push_back(card);
            }
        }
        // 初始胜率计算
        int max_wins = calculate_wins(target_capoo, capoo, table, remaining_cards);
        string best_move = "None";

        // 枚举所有可能的换牌操作
        vector<Card> all_cards = table;
        for (int i = 0; i < 4; ++i)
        {
            all_cards.push_back(capoo[i][0]);
            all_cards.push_back(capoo[i][1]);
        }

        for (size_t i = 0; i < all_cards.size(); ++i)
        {
            for (size_t j = i + 1; j < all_cards.size(); ++j)
            {
                swap(all_cards[i], all_cards[j]);
                vector<Card> new_table = {all_cards[0], all_cards[1], all_cards[2]};
                vector<vector<Card>> new_capoo(4);
                for (int k = 0; k < 4; ++k)
                    new_capoo[k] = {all_cards[3 + 2 * k], all_cards[4 + 2 * k]};

                auto turn = [&](int rank) -> char
                {
                    if (rank < 10)
                        return rank + '0';
                    return "TJQKA"[rank - 10];
                };
                string first = {turn(all_cards[i].rank), all_cards[i].suit};
                string second = {turn(all_cards[j].rank), all_cards[j].suit};
                string move = first + ' ' + second;
                int wins = calculate_wins(target_capoo, new_capoo, new_table, remaining_cards);
                if (wins > max_wins)
                {
                    max_wins = wins;
                    best_move = {turn(all_cards[i].rank), all_cards[i].suit, ' ', turn(all_cards[j].rank), all_cards[j].suit};
                }
                else if (wins == max_wins && best_move != "None")
                {
                    string first = {turn(all_cards[i].rank), all_cards[i].suit};
                    string second = {turn(all_cards[j].rank), all_cards[j].suit};
                    if (first > second)
                        swap(first, second);
                    string move = first + ' ' + second;
                    if (move < best_move)
                        best_move = move;
                }
                swap(all_cards[i], all_cards[j]); // 恢复原来顺序
            }
        }

        cout << best_move << endl;
    }
    return 0;
}
