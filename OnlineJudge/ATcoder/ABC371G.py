from math import gcd

n = int(input())
P = list(map(lambda x : int(x) - 1, input().split()))
A = list(map(int, input().split()))

vis = [-1] * n
cycle = []

pre = 1

ans = A[:]

total_offset = 0

for i in range(n):
    if not ~vis[i]:
        vis[i] = len(cycle)
        cycle.append([i])
        now = cycle[-1]
        nxt = P[i]
        while not ~vis[nxt]:
            vis[nxt] = vis[i]
            now.append(nxt)
            nxt = P[nxt]
        l = len(now)

        choose = l // gcd(pre, l)
        # print(i, pre, total_offset, l)
        offset = min((A[now[(i * pre + total_offset) % l]], i) for i in range(l))[1]
        total_offset += offset * pre
        pre *= choose
        for i in range(l):
            ans[now[i]] = A[now[(i + total_offset) % l]]
print(*ans)

"""
n_1 + k_1 L_1
n_2 + k_2 L_2
"""
