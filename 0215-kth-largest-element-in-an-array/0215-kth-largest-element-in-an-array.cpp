class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int max = INT_MAX;
        int temp = 0;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=0 && temp<k;i--){
            if(nums[i]<=max){
                max=nums[i];
                temp++;
            }
        }
        return max;
    }
};