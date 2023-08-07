class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        sort(A.begin(),A.end());
        int n=A.size();
        vector<vector<int>>res;
        for(int i=0;i<n;)
        {
            int j=i+1;
            for(;j<n;j++)
            {
                if(A[i][1]>=A[j][0])
                {
                    A[i][1]=max(A[i][1],A[j][1]);
                }
                else break;
            }
            res.push_back(A[i]);
            i=j;
        }
        return res;
    }
};