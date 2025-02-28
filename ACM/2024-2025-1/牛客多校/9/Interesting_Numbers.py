n = int(input())
def sqrt(x):
    l = 0
    r = x
    res = 0
    while l <= r:
        mid = l + r >> 1
        if mid * mid <= x:
            res = mid
            l = mid + 1
        else:
            r = mid - 1
    return res
L, R = input().split()
last = int(10 ** (n / 2)) - 1
total = sqrt(last) + 1
def Get(s):
    t = n // 2
    if len(s) < n:
        t -= 1
    up = 0
    if t != 0:
        up = int(s[:t])
    down = int(s[t:])
    p = sqrt(up)
    q = sqrt(down)
    res = 0
    if p * p == up:
        res += q + 1
        p -= 1
    res += p * total
    return res
print(-Get(str(int(L) - 1)) + Get(R))
