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
    vector<vector<int>>ans;
    void solve(TreeNode* root,int k,int sum,vector<int>v)
    {
        if(root==NULL)
        return ;
        sum+=root->val;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==k)
        {
            ans.push_back(v);
            sum=0;
            v={};
            return;
        }
        solve(root->left,k,sum,v);
        solve(root->right,k,sum,v);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp={};
        solve(root,targetSum,0,temp);
        return ans;
        
    }
};