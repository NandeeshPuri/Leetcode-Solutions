class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_set<int> stoneSet(stones.begin(), stones.end());

        vector<vector<bool>> dp(n, vector<bool>(n + 1, false)); // create dp array
        

        dp[0][0] = true;// base case: when frog  start from first stone or we change say if stones.size==1 then it mean start and end index is same
        
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int jump = stones[i] - stones[j];
    
                if (jump <= j + 1) { // check the jump is possible 
                    dp[i][jump] = dp[j][jump - 1] || dp[j][jump] || dp[j][jump + 1]; 
                    // 3 possiblilty 1) jump - 1 2) jump   3) jump + 1
                    if (i == n - 1 && dp[i][jump]) {  //reach last index 
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};