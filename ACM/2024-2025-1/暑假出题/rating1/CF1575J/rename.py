import os
folder_path = 'D:\\Code\\Competition\\ACM\\2024-2025-1\\暑假出题\\rating1\\CF1575J\\data'
exe_path = 'D:\\Code\\Competition\\ACM\\2024-2025-1\\暑假出题\\rating1\\CF1575J\\generator.exe'

# 遍历文件夹中的文件
for filename in os.listdir(folder_path):
    if not filename.endswith('.in'):
        # 构建原始文件和目标文件路径
        old_file = os.path.join(folder_path, filename)
        new_file = os.path.join(folder_path, f'{filename}.in')

        # 重命名文件为num.in
        os.rename(old_file, new_file)
        print(f'Renamed: {old_file} -> {new_file}')
