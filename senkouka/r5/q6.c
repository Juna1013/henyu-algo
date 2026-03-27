#include <stdio.h>

int main(void) {
    int n, m;
    int digits[100]; // 変換後の各桁を保存
    int count = 0;   // 桁数

    printf("n = ");  // 入力
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);

    if (n == 0) {    // n=0の特別処理
        printf("0\n");
        return 0;
    }

    while (n > 0) {  // 繰り返し割り算に余りを保存
        digits[count] = n % m;
        n = n / m;
        count++;
    }

    // 逆順に出力
    printf("m進数:");
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", digits[i]);
    }
    printf("\n");

    return 0;
}
