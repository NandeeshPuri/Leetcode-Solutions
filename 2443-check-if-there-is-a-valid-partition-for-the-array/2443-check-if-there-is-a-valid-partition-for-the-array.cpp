class Solution {
public:
    bool solveMem(vector<int>&nums,vector<int>&dp,int i){
        int n=nums.size(); 

        //base case
        if(i>=n) return true;

        if(dp[i]!=-1){
            return dp[i];
        }
        //For equal elements
        if(i+1<n && nums[i]==nums[i+1]){
            dp[i]=solveMem(nums,dp,i+2);
            if(dp[i]) return true;

            if(i+2<n && nums[i]==nums[i+2]){
                dp[i]=solveMem(nums,dp,i+3);
                if(dp[i]) return true;
            }
        }
        //For 3 consecutive increasing elements
        if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1){
            dp[i]=solveMem(nums,dp,i+3);
            if(dp[i]) return true;
        }

        return false;
    }
    bool validPartition(vector<int>& nums) {
        
        int n=nums.size();
         
         vector<int>dp(n+1,-1);

         return solveMem(nums,dp,0);


    }
};