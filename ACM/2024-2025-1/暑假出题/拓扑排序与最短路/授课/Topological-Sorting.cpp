#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> in(n + 1);
    vector<vector<int>> E(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int u, v;
        cin >> u >> v;
        //加边的过程处理in入度数组
        E[u].push_back(v);
        ++in[v];
    }
    //也可以是stack
    //或者你自己手写的stack数组之类的
    //代码常数可能就比较小
    //priority_queue的话就是在拓扑序的基础上以标号的顺序为第二关键字
    //即字典序最小/最大的拓扑序
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
        if (!in[i])
            Q.push(i);
    vector<int> ans;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        ans.push_back(u);
        for (int v : E[u])
            if (!--in[v])//删除边的同时把入度为0的加入集合Q中
                Q.push(v);
    }
    if (ans.size() != n)//遍历的点数不为全集，即含环
        cout << "Impossible" << endl;
    else
        for (int i = 0; i < n; ++i)
            cout << ans[i] << " \n"[i == n - 1];

}
