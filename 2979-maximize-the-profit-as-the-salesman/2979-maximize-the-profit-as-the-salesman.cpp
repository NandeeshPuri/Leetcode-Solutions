class Solution {
public:
       int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n + 1);
        vector<vector<vector<int>>> m(n);
        for (auto& a : offers) {
            m[a[1]].push_back(a);
        }
        for (int e = 1; e <= n; e++) {
            dp[e] = dp[e - 1];
            for (auto& a : m[e - 1]) {
                dp[e] = max(dp[e], dp[a[0]] + a[2]);
            }
        }
        return dp[n];
    }
};