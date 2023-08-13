class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> dp(nums.size()+1);
        
        dp[0] = true;
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = dp[i-2] && nums[i-1] == nums[i-2];
            if (i > 2) {
                dp[i] = dp[i] || (dp[i-3] && nums[i-1] == nums[i-2] && nums[i-2] == nums[i-3]);
                dp[i] = dp[i] || (dp[i-3] && nums[i-1] == nums[i-2] + 1 && nums[i-2] == nums[i-3]+1);
            }
        }
        
        return dp[nums.size()];
    }
};