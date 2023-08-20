class Solution 
{
public:
    void solve(int ind, vector<int>&candidates, int &target, int sum, vector<vector<int>>&result , vector<int>&ans) 
    {
        if(ind == candidates.size())
        {
            // if(sum == target)
            // {
            //     result.push_back(ans);
            // }
            return;
        }

        if(sum >= target)
        {
            if(sum == target)
            {
                result.push_back(ans);
            }
            return;
        }
            ans.push_back(candidates[ind]);
            sum = sum + candidates[ind];
            solve(ind, candidates, target, sum, result, ans);

            ans.pop_back();
            sum -= candidates[ind];
            solve(ind+1, candidates, target, sum, result, ans);
         
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>result;
        vector<int>ans;
        solve(0, candidates, target, 0, result, ans);
        return result;
    }
};