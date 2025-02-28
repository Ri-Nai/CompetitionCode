cards = [i for i in range(1, 14)]
ans = 0

def fac(n):
    if n == 0:
        return 1
    return n * fac(n - 1)
one = 12 - 5 + 1
two = 0
for i in range(6, 13): # 5 ~ 12
    j = 12 - i
    if j < 5:
        break
    two += j - 5 + 1
ans = 0
ans += fac(13)
ans += fac(13 - 5 + 1) * one
ans += fac(13 - 5 + 1 - 5 + 1) * two
print(ans)
