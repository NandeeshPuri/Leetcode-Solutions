class Solution {
public:
     bool search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
       
        while(l<=h)                                //  Loop When all elements are same except one              
           { int mid=(l+h)/2;
             if(nums[mid]==target ||nums[l]==target || nums[h]==target)
               return true;
             l++,h--;     
           }
        l=0,h=nums.size()-1;
        while (l <= h)
           { int mid = (l + h) / 2;
              if (nums[mid] == target) return true;
                     
              if (nums[l] <= nums[mid])     //Means left side is sorted//
                 {   if (nums[l] <= target && target <= nums[mid])  // Element may present on left part
                          h = mid - 1;
                     else                     //  Element  present on right part
                          l = mid + 1;
                }
              else
                 {  if(target >= nums[mid] && target <= nums[h])         //  Element  present on right part
                        l = mid + 1;
                   else                                   //  Element  present on left part
                       h = mid - 1;
                }
          }
         return false;
    }
};