#include <stdio.h>
#define N 6

int next_partition(int a[]) {
    int k = 0;
    int r = 0;

    while (k < N && a[k+1] != 0) {
        k++;
    }

    // (A)
    while (a[k] == 1) {
        r++;
        k--;
    }

    if (k < 0) return 0;

    a[k]--;
    r++;

    while (r > a[k]) {
        a[k+1] = a[k]; // X
        r = r - a[k];
        k++;
    }

    a[k+1] = r;
    a[k+2] = 0;

    return 1;
}

int is_all_odd(int a[]) {
    int i = 0;

    while (a[i] != 0) { // (B)
        if (a[i++] % 2 != 1) {
            return 0;
        }
    }
    return 1;
}

int is_all_distinct(int a[]) {
    int i = N;
    int check[N];
    do {
        i--;
        check[i] = 0;
    } while (i > 0);

    while (a[i] != 0) { // (C)
        if (check[a[i]-1] != 0) {
            return 0;
        }
        check[a[i++]-1] = 1;
    }

    return 1;
}

int odd_to_distinct(int a[]) {
    int i = 0;
    int j;

    do { // (D)
        if (a[i] == a[i+1]) {
            a[i] *= 2;
            j = i + 1;
            while (a[j] != 0) {
                a[j] = a[j+1];
                j++;
            }
        }

        if (i > 0 && a[i-1] == a[i]) {
            i--;
        } else {
            i++;
        }
    } while (a[i] != 0);
}
