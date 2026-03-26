# 再帰を用いないフィボナッチ数列
n = int(input())

if n == 1 or n == 2:
    print(1)
else:
    a = 1 # n-2の値
    b = 1 # n-1の値
    for i in range(3, n+1):
        c = a + b # n-1とn-2の和
        a = b     # 次のループに向けて更新
        b = c
    print(b)
