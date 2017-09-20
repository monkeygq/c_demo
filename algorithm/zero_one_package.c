#include <stdio.h>

int max(int a, int b);

int main() {
    int weight[5] = {2,2,6,5,4};//物品数量5
    int value[5] = {6,3,5,4,6};
    int package = 10;//背包容量10
    int dp[5][11];
    int i, j;
    for(i = 0; i < 5; i++) {
        for(j = 0; j <= package; j++) {
            if(i - 1 < 0) {
                if(j - weight[i] < 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = value[i];
            }
            else {
                if(j - weight[i] < 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j-weight[i]] + value[i], dp[i-1][j]);
            }
        }
    }
    for(i = 0; i < 5; i++) {
        for(j = 0; j <= package; j++)
            printf("%3d ", dp[i][j]);
        printf("\n");
    }
    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

