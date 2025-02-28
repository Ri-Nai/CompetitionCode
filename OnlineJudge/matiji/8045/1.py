n, m, p = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
def add(x : int, y : int) -> int:
    x += y
    if x >= p:
        x -= p
    return x
ans = [0] * p
for i in range(p):
    cnt = [0] * p
    for x in b:
        now = add(x, i)
        ans[i] += sum(cnt[now + 1 :])
        cnt[now] += 1
res = 0
from collections import Counter
cntb = Counter(b)
cnt = [0] * p
for x in a:
    for y in range(p):
        cnt[add(x, y)] += cntb[y]
for x in a:
    res += ans[x]
    cntnow = [0] * p
    for i in range(p):
        cntnow[add(x, i)] += cntb[i]
    for i in range(p):
        cnt[i] -= cntnow[i]
    for i in range(p):
        for j in range(i + 1, p):
            res += cnt[i] * cntnow[j]
print(res)
