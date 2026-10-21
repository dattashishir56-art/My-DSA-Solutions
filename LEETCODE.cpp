class Solution {
public:
    
        int change(int amount, vector<int>& coins) {
    int m = coins.size();
    // dp[i][n] = number of ways to make amount n using coins[i..m-1]
    vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(amount + 1, 0));

    // Base case: amount 0 can always be made in exactly 1 way (pick nothing)
    for (int i = 0; i <= m; i++) dp[i][0] = 1;

    // i == m (no coins left) and n > 0 stays 0 from initialization

    for (int i = m - 1; i >= 0; i--) {
        for (int n = 1; n <= amount; n++) {
            // skip coin i
            dp[i][n] = dp[i + 1][n];
            // take coin i (stay on i, since coins are reusable)
            if (n - coins[i] >= 0)
                dp[i][n] += dp[i][n - coins[i]];
        }
    }
    return (int)dp[0][amount];

    } 
};