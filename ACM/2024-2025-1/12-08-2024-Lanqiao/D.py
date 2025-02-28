n = int(input())
x, y, z = map(int, input().split())
a = [0]
f = [0]
ans = [None] * n
for i in range(n):
    a.append((a[-1] * x + y) % z)
for k in range(n):
    ans[k] = min(max(a[i : i + k + 1]) for i in range(1, 1 + n - k))
for i in range(n):
    f.append((x * f[-1] + ans[i] + y) % z)
print(f[-1])
# print(" ".join(map(str, ans)))
