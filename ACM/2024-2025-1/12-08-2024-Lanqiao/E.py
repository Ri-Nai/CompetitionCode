import random

random.seed(1)
n = 5
m = 5
a = [
    [
        random.choice(
            (0, random.randint(1, 100), random.randint(1, 100), random.randint(1, 100))
        )
        for j in range(m + 1)
    ]
    for i in range(n + 1)
]
"""
n = 2
m = 2
a = [
    [0, 0, 0],
    [0, 0, 3],
    [0, 5, 4]
]
"""

print(a)
x = 2
y = 2
def get_next(board, x, y, player):
    func = min if player else max
    possibles = [(x + i, y + j) for i, j in [(0, 1), (0, -1), (1, 0), (-1, 0)]]
    # print(board)
    # print(n, m)
    positions = []
    for nx, ny in possibles:
        if 1 <= nx <= n and 1 <= ny <= m and board[nx][ny] > 0:
            positions.append((nx, ny))
    if not positions:
        return board[x][y], None
    global a
    board[x][y] = 0
    best_position = func(
        (get_next(board, nx, ny, player ^ 1)[0], (nx, ny))
        for nx, ny in positions
    )
    board[x][y] = a[x][y]
    return best_position[0] + a[x][y], best_position[1]
player = 0
# ans = a[x][y]
# a[x][y] = 0
ans = 0
while True:
    ans += a[x][y]
    a[x][y] = 0
    res = get_next(a, x, y, player)
    # print(res)
    if not res[0]:
        break
    x, y = res[1]
    print(x, y)
    player ^= 1
# print(ans, a)
print(ans)
for t in a:
    print(t)
"""
[
 0, 28, 93, 98, 45],
 0, 81, 43, 86, 64],
 96, 71, 0, 67, 0],
 83, 2, 66, 0, 50],
 8, 26, 46, 69, 59]
 ]

[
[0, 28, 0, 0, 0]
[0, 0, 0, 0, 0]
[0, 0, 0, 67, 0]
[0, 0, 0, 0, 50]
[8, 0, 0, 0, 0]
"""
