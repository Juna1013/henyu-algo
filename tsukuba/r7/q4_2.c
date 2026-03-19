// 基数ソート
#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 100

// 循環バッファとして動くキューの構造体を定義する
typedef struct queue {
    int *buffer; // データを格納する配列（動的確保）
    int length;  // バッファの最大サイズ
    int front;   // 次にデキュー（取り出し）する位置のインデックス
    int rear;    // 次にエンキュー（追加）する位置のインデックス
} Queue;

// キューを使える状態に初期化
void q_init(Queue *this_queue, int len) {
    this_queue->buffer = (int*)malloc(sizeof(int) * len);
    this_queue->length = len;
    this_queue->front = 0;
    this_queue->rear = 0;
}

// キューに値を追加する関数
void q_enq(Queue *this_queue, int d) {
    this_queue->buffer[this_queue->rear] = d; //（ア）
    this_queue->rear = (this_queue->rear + 1) % this_queue->length;
}

// キューから値を取り出す関数
int q_deq(Queue *this_queue) {
    int x = this_queue->buffer[this_queue->front]; //（イ）
    this_queue->front = (this_queue->front + 1) % this_queue->length;
    return x;
}

// キューが空かどうかを判定する関数
int q_is_empty(Queue *this_queue) {
    if (this_queue->front == this_queue->rear) { //（ウ）
        return 1;
    } else {
        return 0;
    }
}

// メモリ解放
void q_remove(Queue *this_queue) {
    free(this_queue->buffer);
}

void radix_sort(int a[], int n, int k) {
    // 10進数なので、10個のバケットを用意
    Queue *b = (Queue *)malloc(sizeof(Queue) * 10);
    int i, j, m;
    for (i = 0; i < 10; i++) {
        q_init(&b[i], n+1);
    }

    // 下の桁から順番に桁ごとにバケットソートを行うという操作をk回繰り返す
    for (i = 1, m = 1; i <= k; i++, m += 10) {
        int idx_d; // 配列aの要素のインデックス
        int idx_q; // バケットのインデックス
        for (idx_d = 0; idx_d < n; idx_d++) {
            int radix = (a[idx_d]/m) % 10; //（カ）
            q_enq(&b[radix], a[idx_d]); //（キ）
        }
        for (idx_d = 0, idx_q = 0; idx_q < 10; idx_q++) {
            while (q_is_empty(&b[idx_q] != 1)) { //（ク）
                a[idx_d] = q_deq(&b[idx_q]); //（ケ）
                idx_d++;
            }
        }
        // 配列aの中身を標準出力
        for (j = 0; j < n; j++) {
            printf("%d", a[j]);
        }
        printf("\n");
    }
    // Queue array deleted
    for (i = 0; i < 10; i++) {
        q_remove(&b[i]);
    }
    free(b);
}
