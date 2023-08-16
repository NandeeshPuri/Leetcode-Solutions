class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int>ans;
		deque<int>dq;
		int n=nums.size();
		int i=0,j=0;
		while(j<n){
			while(dq.size() && nums[dq.back()]<nums[j]) dq.pop_back();
			dq.push_back(j);
			if(j-i+1==k){
				ans.push_back(nums[dq.front()]);
				if(dq.front()==i){
					dq.pop_front();
				}
				i++;
			}
			j++;
		}
		return ans;
	}
};