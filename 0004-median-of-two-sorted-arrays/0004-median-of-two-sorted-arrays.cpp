class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    
    vector<double> res;
    
    for(int i=0;i<n;i++){
        res.push_back(nums1[i]);
    }
    
    for(int i=0;i<m;i++){
        res.push_back(nums2[i]);
    }
    
    sort(res.begin(),res.end());
    
    int k = res.size();
    double ans = 0;
    
    if(k%2 == 0){
        
        int idx = k/2;
        ans = (res[idx] + res[idx-1])/2;
        
    }else{
        int idx = k/2;
        ans = res[idx];
    }
    return ans;
    
}

};