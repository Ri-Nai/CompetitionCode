import os
import subprocess

# 定义文件夹路径和exe文件路径
folder_path = 'D:\\Code\\Competition\\ACM\\2024-2025-1\\暑假出题\\rating1\\CF1575J\\data'
exe_path = 'D:\\Code\\Competition\\ACM\\2024-2025-1\\暑假出题\\rating1\\CF1575J\\CF1575J.exe'

for filename in os.listdir(folder_path):
    if filename.endswith('.in'):
        # 构建输入和输出文件路径
        input_file = os.path.join(folder_path, filename)
        output_file = os.path.join(folder_path, filename.replace('.in', '.out'))

        # 调用外部exe处理输入文件
        # subprocess.run([exe_path, input_file, output_file])
        os.system(exe_path + " < " + input_file + " > " + output_file)

        # 打印处理完成的信息
        print(f'Processed: {input_file} -> {output_file}')
