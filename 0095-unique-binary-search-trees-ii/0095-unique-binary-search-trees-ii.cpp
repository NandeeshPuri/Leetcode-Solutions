/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int num;
    vector<TreeNode*> generateTrees(int n) {
        num=n;
        vector<TreeNode*> step=generate(1,n);
        return step;
    }
    vector<TreeNode*> generate(int start,int end)
    {
        if(start>end)
            return {NULL};
        vector<TreeNode*> left,right;
        vector<TreeNode*> ans;
        if(start==end)
            return {new TreeNode(start)};
        for(int i=start;i<=end;i++)
        {
                left=generate(start,i-1);
                right=generate(i+1,end);
            for(int j=0;j<left.size();j++)
            {
                for(int k=0;k<right.size();k++)
                {
                    TreeNode* step=new TreeNode(i);
                    step->left=left[j];
                    step->right=right[k];
                    ans.push_back(step);
                }
            }
        }
        return ans;
    }
    
};