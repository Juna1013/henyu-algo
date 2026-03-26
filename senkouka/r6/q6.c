#include <stdio.h>

int main(void) {
    int n, a, b, c, i;
    scanf("%d", &n);

    if (n == 1 || n == 2) {
        printf("1\n");
    } else {
        a = 1;
        b = 1;
        for (i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        printf("%d\n", b);
    }

    return 0;
}
