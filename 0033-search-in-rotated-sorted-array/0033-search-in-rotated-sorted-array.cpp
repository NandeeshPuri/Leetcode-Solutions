class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(find(nums.begin(),nums.end(),target)==nums.end())return -1;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=target)c++;
            else break;
        }
        return c;
    }
};