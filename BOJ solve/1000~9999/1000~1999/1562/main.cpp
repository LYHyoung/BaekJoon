#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
long long ans, n, dp[101][1025][10], m = 1000000000;

int main() {
    scanf("%lld", &n);
    for (int i = 1; i < 10; i++)dp[0][1 << i][i] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1024; j++) {
            dp[i + 1][(1 << 1) | j][1] = (dp[i + 1][(1 << 1) | j][1] + dp[i][j][0]) % m;
            for (int k = 1; k < 9; k++) {
                int down = k - 1, up = k + 1;
                dp[i + 1][(1 << down) | j][down] = (dp[i + 1][(1 << down) | j][down] + dp[i][j][k]) % m;
                dp[i + 1][(1 << up) | j][up] = (dp[i + 1][(1 << up) | j][up] + dp[i][j][k]) % m;
            }
            dp[i + 1][(1 << 8) | j][8] = (dp[i + 1][(1 << 8) | j][8] + dp[i][j][9]) % m;
        }
    }
    for (int i = 0; i < 10; i++)ans = (ans + dp[n - 1][1023][i]) % m;
    printf("%lld", ans);
}