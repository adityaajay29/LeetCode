int dp[1001][1001] = {1};
int modulo = 1e9 + 7;
class Solution {
public:
    int kInversePairs(int n, int k) {
        if (dp[n][k])
            return dp[n][k];
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K) {
                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % modulo;
                if (K >= N)
                    dp[N][K] = (modulo + dp[N][K] - dp[N - 1][K - N]) % modulo;
            }
        return dp[n][k];
    }
};
