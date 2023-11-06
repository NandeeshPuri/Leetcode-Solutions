class Solution {
public:
    //merge two sorted logic:
    void merge(vector<int> &nums, int l, int m, int r){
      int count = 0;

      //copy into right & left array
      vector<int>left(nums.begin()+l,nums.begin()+m+1);
      vector<int>right(nums.begin()+m+1,nums.begin()+r+1);

      int i = 0, j = 0, n1 = left.size(),n2 = right.size();
      
      while(i < n1 && j < n2){
          if (left[i] <= right[j])
              nums[l++] = left[i++];
          else{
            nums[l++] = right[j++];
          }     
      }
      while (i < n1)
          nums[l++] = left[i++];
      while (j < n2)
          nums[l++] = right[j++];
  }
  //count pair 
  int countPairs(vector<int>&nums,int l, int m, int r){
      int count = 0;
      for(int i = l, j = m+1; i <= m; i++){
          while(j <= r && nums[i] > 2LL*nums[j]) j++;
          count += j-(m+1);
      }
      return count;
  }
  int mergeSort(vector<int> &nums, int l, int r){
      int count = 0;
      if (l == r) return count;
      
      int m = l + (r-l)/2;
      //left part sort
      count += mergeSort(nums,l,m);
      //right part sort
      count += mergeSort(nums,m+1,r);
      //count pairs
      count += countPairs(nums,l,m,r);
      //merge these sorted array
      merge(nums,l,m,r);
      return count;
  }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};