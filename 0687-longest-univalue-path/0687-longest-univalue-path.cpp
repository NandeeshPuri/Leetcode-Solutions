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
   int height(TreeNode * root,int& dis){
       if(!root)return 0;
        int l=height(root->left,dis);
        int r=height(root->right,dis);
        int dl=(root->left and root->val==root->left->val)?l+1:0;
        int dr=(root->right and root->val==root->right->val)?r+1:0;
        dis=max(dis,dl+dr);
        return max(dl,dr);
   }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)return 0;
        int dis=0;
         height(root,dis);
         return dis;
    }
};