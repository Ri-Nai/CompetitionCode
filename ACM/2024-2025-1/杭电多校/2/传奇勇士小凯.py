def main():
    n = int(input())
    Edge = [[] for i in range(n + 1)]
    for i in range(n - 1):
        u, v = map(int, input().split())
        Edge[u].append(v)
        Edge[v].append(u)
    p = [0] + list(map(int, input().split()))
    dpf = [0] * (n + 1)
    dpg = [1] * (n + 1)
    def gcd(a, b):
        if b == 0:
            return a
        return gcd(b, a % b)
    def dfs(u, f):
        maxf = 0
        maxg = 1
        for v in Edge[u]:
            if v == f:
                continue
            dfs(v, u)
            if dpf[v] * maxg > dpg[v] * maxf:
                maxf = dpf[v]
                maxg = dpg[v]
        g = maxg // gcd(maxg, p[u]) * p[u]
        dpf[u] = g // maxg * maxf + g // p[u] * 15
        dpg[u] = g
        g = gcd(dpf[u], dpg[u])
        dpf[u] //= g
        dpg[u] //= g
    dfs(1, 0)
    print(dpf[1], dpg[1], sep = '/')
T = int(input())
while T:
    T -= 1
    main()
