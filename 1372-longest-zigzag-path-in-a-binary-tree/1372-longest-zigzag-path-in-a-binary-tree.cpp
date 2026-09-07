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
    int ans=0;
    pair<int,int>solve(TreeNode* root)
    {
        if(root==NULL)
        return {0,0};

        auto left=solve(root->left);
        auto right=solve(root->right);
        int leftPath=0;
        int rightPath=0;
       if(root->left)
       {
        leftPath=left.second+1;
       }
       if(root->right)
       rightPath=right.first+1;

        ans=max(ans,max(leftPath,rightPath));
        return {leftPath,rightPath};



    }
    int longestZigZag(TreeNode* root) {
        
        auto x=solve(root);
        return ans;
        
    }
};