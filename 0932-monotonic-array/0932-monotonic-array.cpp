class Solution {
public:
  bool isMonotonic(vector<int>& nums) {
        int k = 1; 
        //check if all the numbers are same or not
        while(k < nums.size() && nums[k] == nums[k-1]) ++k;    
        if(k == nums.size()) return true;
        
        int f = 0; 
        if(nums[k-1] < nums[k])  f = 1;   
        for(int i = k; i < nums.size(); ++i){
            if((f== 1 && nums[i-1] > nums[i]) ||  (f== 0 && nums[i-1] < nums[i])){
                return false;
            }
        }
        return true;
    }
};