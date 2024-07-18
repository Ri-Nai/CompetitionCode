#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, a[N][N][4], q;// a b l r
char s[N][N];
struct Node{
    int x, y, dir;
}st[N * N];
int trans(int dir, char c){
    if(c == '-' && dir <= 1) return 1 - dir;
    else if(c == '-') return dir;
    else if(c == '|' && dir >= 2) return 5 - dir;
    else if(c == '|') return dir;
    else if(c == '\\'){
        if(dir == 0) return 2;
        else if(dir == 1) return 3;
        else if(dir == 2) return 0;
        else return 1;
    }
    else{
        if(dir == 0) return 3;
        else if(dir == 1) return 2;
        else if(dir == 2) return 1;
        else return 0;
    }
}
int cnt;
bool flag = false;
int dfs(int x, int y, int dir){
    if(a[x][y][dir]){
        if(a[x][y][dir] == -1){flag = 1; return a[x][y][dir] = cnt;}
        else return a[x][y][dir];
    }
    if(x < 1 || y < 1 || x > n || y > m) return 0;
    int tdir = trans(dir, s[x][y]);
    a[x][y][dir] = -1;
    if(tdir == dir){
        if(dir == 0) return a[x][y][dir] = dfs(x - 1, y, dir);
        else if(dir == 1) return a[x][y][dir] = dfs(x + 1, y, dir);
        else if(dir == 2) return a[x][y][dir] = dfs(x, y - 1, dir);
        else return a[x][y][dir] = dfs(x, y + 1, dir);
    }
    else{
        cnt++;
        int tans;
        if(tdir == 0) tans = dfs(x - 1, y, tdir);
        else if(tdir == 1) tans = dfs(x + 1, y, tdir);
        else if(tdir == 2) tans = dfs(x, y - 1, tdir);
        else tans = dfs(x, y + 1, tdir);
        if(flag) return a[x][y][dir] = cnt;
        else return a[x][y][dir] = tans + 1;
    }
}
int getans(int x, int y, int dir){
    flag = 0, cnt = 0;
    if(dir == 0) return dfs(x - 1, y, dir);
    else if(dir == 1) return dfs(x + 1, y, dir);
    else if(dir == 2) return dfs(x, y - 1, dir);
    else return dfs(x, y + 1, dir);
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    scanf("%d", &q);
    while(q--){
        int x, y, dir;
        char t[15];
        scanf("%d%d%s", &x, &y, t + 1);
        if(t[1] == 'a') dir = 0;
        else if(t[1] == 'b') dir = 1;
        else if(t[1] == 'l') dir = 2;
        else dir = 3;
        printf("%d\n", getans(x, y, dir));
    }
    return 0;
}
