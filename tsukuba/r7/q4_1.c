// バケットソート
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

void bucket_sort(int a[], int n) {
    Queue *b = (Queue *)malloc(sizeof(Queue) * (MAX_VAL + 1));
    int i;
    for (i = 0; i <= MAX_VAL; i++) {
        q_init(&b[i], n+1);
    }
    for (i = 0; i < n; i++) {
        q_enq(&b[a[i]], a[i]); //（エ）
    }
    int j = 0;
    for (i = 0; i <= MAX_VAL; i++) {
        while (q_is_empty(&b[i]) != 1) {
            a[j] = q_deq(&b[i]); //（オ）
            j++;
        }
    }
    // Queue array deleted
    for (i = 0; i <= MAX_VAL; i++) {
        q_remove(&b[i]);
    }
    free(b);
}
