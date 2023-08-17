class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2,nums1);
        }

        int left = (nums1.size() + nums2.size() + 1) / 2;
        int low = 0;
        int high = nums1.size();
        while(low <= high){
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            int L1 = INT_MIN, L2 = INT_MIN;
            int R1 = INT_MAX, R2 = INT_MAX;
            if(mid1 - 1 >= 0) L1 = nums1[mid1-1];
            if(mid2 - 1 >= 0) L2 = nums2[mid2-1];
            if(mid1 < nums1.size()) R1 = nums1[mid1];
            if(mid2 < nums2.size()) R2 = nums2[mid2];

            if(L1 <= R2 && L2 <= R1){
                if((nums1.size() + nums2.size()) % 2 == 0){
                    return ((double)(max(L1,L2) + min(R1,R2))) / 2.0;    
                }
                else{
                    return max(L1,L2);
                }
            }
            else if(L1 > R2){
                high = mid1 - 1;
            }
            else{
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};