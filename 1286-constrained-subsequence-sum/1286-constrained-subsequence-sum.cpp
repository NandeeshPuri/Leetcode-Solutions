class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> queue;  // Create a double-ended queue (deque) to store indices of elements.
        vector<int> dp(nums.size());  // Create a vector `dp` to store dynamic programming values.

        for (int i = 0; i < nums.size(); i++) {
            // Ensure that the queue only contains indices within the sliding window size `k`.
            if (!queue.empty() && i - queue.front() > k) {
                queue.pop_front();  // Remove elements that are outside the window.
            }

            // Calculate `dp[i]` as the maximum of the current element and the maximum from the previous window.
            dp[i] = (!queue.empty() ? dp[queue.front()] : 0) + nums[i];

            // Remove elements from the back of the queue if their corresponding `dp` values are smaller than `dp[i]`.
            while (!queue.empty() && dp[queue.back()] < dp[i]) {
                queue.pop_back();
            }

            // If the calculated `dp[i]` is positive, add the current index `i` to the queue.
            if (dp[i] > 0) {
                queue.push_back(i);
            }
        }

        // Return the maximum value in the `dp` vector, which represents the maximum sum of a constrained subset.
        return *max_element(dp.begin(), dp.end());
    }
};