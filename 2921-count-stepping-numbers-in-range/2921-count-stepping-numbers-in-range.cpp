int dp[101][10] = {}, m = 1000000007;
class Solution {
public:
int dfs(int i, int p, const string &n, bool lim) {
    if (p < 0 || p > 9 || (lim && p > (n[n.size() - i] - '0')))
        return 0;
    if (i == 1)
        return 1;    
    lim &= p == (n[n.size() - i] - '0');
    if (lim)
        return (dfs(i - 1, p - 1, n, lim) + dfs(i - 1, p + 1, n, lim)) % m;
    if (dp[i][p] == 0)
        dp[i][p] = (1 + dfs(i - 1, p - 1, n, lim) + dfs(i - 1, p + 1, n, lim)) % m;
    return dp[i][p] - 1;
}
int count(const string &n) {
    int res = 0;
    for (int sz = 1; sz <= n.size(); ++sz)
        for (int d = 1; d <= 9; ++d)
            res = (res + dfs(sz, d, n, sz == n.size())) % m;   
    return res;
}
int countSteppingNumbers(const string &low, const string &high) {
    return (m + count(high) - count(low) + 
        equal(begin(low) + 1, end(low), begin(low), [](int a, int b){
            return abs(a - b) == 1;
        })) % m;
}
};