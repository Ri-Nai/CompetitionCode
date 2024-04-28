def has_subsequence_with_sum(seq, k):
    n = len(seq)
    for i in range(1, 1 << n):
        subset_sum = 0
        for j in range(n):
            if (i >> j) & 1:
                subset_sum += seq[j]
        if subset_sum == k:
            return True
    return False

def generate_sequence(n, k, seq=[], index=1):
    if index > n:
        return None

    for i in range(1, n + 1):
        new_seq = seq + [i]
        if not has_subsequence_with_sum(new_seq, k):
            flag = 1
            for j in range(1, n + 1):
                if j == k:
                    continue
                if not has_subsequence_with_sum(new_seq, j):
                    flag = 0
            if flag == 1:
                return new_seq
        nxt = generate_sequence(n, k,new_seq, index + 1)
        if nxt != None:
            return nxt
    return None

n = 9  # 代表1~n中的整数
k = 5   # 需要避免的和

result = generate_sequence(n, k)
if result:
    print("满足条件的序列：", result)
else:
    print("无法生成满足条件的序列。")
