dic = {
    202 : 0,
    41 : 0,
    27 : 0,
    3 : 0,
}
for i in range(101):
    for j in range(101):
        for k in range(101):
            now = i * 1 + j * 2 + k * 3
            for key in dic.keys():
                if now == key:
                    dic[now] += 1
print(dic)
