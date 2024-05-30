#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=1e6+5;
    long long count=0;
    int A[M],n;
    long long quickSort(int *num, const int &begin, const int &end) {
        if (begin >= end)return 0;
        int count = 0, *left_num, *right_num;
        int pivot = num[begin];
        right_num = new int[end - begin];
        int left = begin + 1, left_pos = begin, temp = 0;
        bool flag = true;
        while (left <= end) {
        ++count;
        if (num[left] < pivot) {
            num[left_pos] = num[left];
            ++left_pos;
        } else {
            right_num[temp] = num[left];
            ++temp;
        }
        ++left;
        }
        num[left_pos] = pivot;
        for (int i = 0; i < temp; ++i) {
        num[left_pos + i + 1] = right_num[i];
        }
        delete[]right_num;
        return count + quickSort(num, begin, left_pos - 1) + quickSort(num, left_pos + 1, end);
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>A[i];
        cout<<quickSort(A,1,n);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
