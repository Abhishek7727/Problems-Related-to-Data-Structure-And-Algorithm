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
    TreeNode* solve(vector<int>&post,vector<int>&in, int& index,int inStart,int inEnd,int n,unordered_map<int,int>&mp)
    {
        if(n<0 || inStart>inEnd)
        return NULL;

        TreeNode* root=new TreeNode(post[index--]);
        int pos=mp[root->val];

        root->right=solve(post,in,index,pos+1,inEnd,n,mp);
        root->left=solve(post,in,index,inStart,pos-1,n,mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;

        int n=postorder.size();
        int postIndex=n-1;
        TreeNode* root=solve(postorder,inorder,postIndex,0,n-1,n,mp);
        return root;
        
    }
};