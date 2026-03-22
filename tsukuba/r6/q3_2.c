// フィボナッチ数列の高速化（非再起）
#define MAX_SIZE 2000
long g(int n) {
    long a[MAX_SIZE];
    a[1] = a[2] = 1;
    for (int i = 3; i <= n; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}
