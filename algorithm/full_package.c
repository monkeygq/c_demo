#include <stdio.h>

int max(int a, int b);

int main() {
    int weight[5] = {2,2,6,5,4};//物品数量5
    int value[5] = {6,3,5,4,6};
    int package = 10;//背包容量10
    int dp[11];
    int i, j;
    for(i = 0; i <= package; i++)
        dp[i] = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j <= package; j++) {
            if(j - weight[i] >= 0)
                dp[j] = max(dp[j-weight[i]] + value[i], dp[j]);
            printf("%d ", dp[j]);
        }
        printf("\n");
    }
    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

