// 再帰を用いたフィボナッチ数列
long f(int n) {
    if (n < 3) {
        return 1;
    } else {
        return f(n-1) + f(n-2);
    }
}