class Solution {
public:
    
    int trap(vector<int>& height) {
        
        // brute force
        // int ans = 0;
        // int size = height.size();
        // for (int i = 1; i < size - 1; i++) {
        //     int left_max = 0, right_max = 0;
        //     for (int j = i; j >= 0; j--) { //Search the left part for max bar size
        //         left_max = max(left_max, height[j]);
        //     }
        //     for (int j = i; j < size; j++) { //Search the right part for max bar size
        //         right_max = max(right_max, height[j]);
        //     }
        //     ans += min(left_max, right_max) - height[i];
        // }
        // return ans;

        // optimal 

        int n = height.size();
        int left = 0,right = n-1;
        int res = 0;
        int left_max = 0,right_max = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= left_max){
                    left_max = height[left];
                }
                else{
                    res += left_max - height[left];
                }
                left++;
            }
            else{
                if(height[right] >= right_max){
                    right_max = height[right];
                }
                else{
                    res += right_max - height[right];
                }
                right--;
            }
        }
        return res;

    }
};