#include <stdio.h>

#define LEARNING_RATE 0.1 // 学習率
#define NUM_EPOCHS 10    // エポック数
#define NUM_SAMPLES 4   // 学習データ数
#define NUM_DIMS 2     // 入力データの次元数

// 入力データ
int X_in[NUM_SAMPLES][NUM_DIMS] = {
    {0, 0}, {0, 1}, {1, 0}, {1, 1}
};
int G[NUM_SAMPLES] = {0, 1, 1, 1}; // 入力データに対する正解値

// ステップ関数
int step_function(double z) {
    if (z > 0) { //（ア）
        return 1; //（イ）
    } else {
        return 0;
    }
}

// 単純パーセプトロン
int predict(double w[NUM_DIMS], int x[NUM_DIMS], double bias) {
    double z = 0.0;
    for (int i = 0; i < NUM_DIMS; i++) {
        z += w[i] * x[i]; //（ウ）
    }
    return step_function(z + bias); //（エ）
}

int main() {
    double weights[NUM_DIMS] = {0.0, 0.0};
    double bias = 0.0;

    // 単純パーセプトロンの学習
    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
        for (int k = 0; k < NUM_SAMPLES; k++) {
            int y_pred = predict(weights, X_in[k], bias);
            double error = G[k] - y_pred;
            for (int i = 0; i < NUM_DIMS; i++) {
                weights[i] += LEARNING_RATE * error * X_in[k][i]; //（オ）
            }
            bias += LEARNING_RATE * error; //（カ）
        }
    }

    return 0;
}
