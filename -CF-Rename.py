import os
dict = {}
with open('tmp.html', 'r') as f:
    lines = f.readlines()

    last = False
    # for i in range(len(lines)):
    i = 0
    while i < len(lines):
        if '/problemset/problem/' in lines[i]:
            id = lines[i + 1].strip()
            name = lines[i + 7][:-5].strip().replace(' ', '_')
            # print(id, name)
            dict[name] = id
            i += 7
        i += 1

# 遍历当前文件夹下的所有文件，若文件夹的名字在dict中，则重命名为f`CF{id}.{后缀}`
# for root, dirs, files in os.walk('.'):
files = os.listdir('.')
for file in files:
    # print(file)
    for name, id in dict.items():
        if name in file:
            suffix = file.split('.')[-1]
            os.rename(file, f'CF{id}.{suffix}')
            # print(file, f'CF{id}.{suffix}')
            break
