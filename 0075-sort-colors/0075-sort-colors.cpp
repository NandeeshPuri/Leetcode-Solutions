class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int lo = 0, mid = 0, hi = nums.size()-1; mid <= hi; ) {
            if (nums[mid] == 0) swap(nums[lo++], nums[mid++]); 
            else if (nums[mid] == 2) swap(nums[mid], nums[hi--]); 
            else ++mid; 
        }
    }
};