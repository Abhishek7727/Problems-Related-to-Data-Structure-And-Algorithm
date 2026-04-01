class Solution {
public:
bool solve(TreeNode* root,int k,int sum)
    {
        if(root==NULL)
        return false;
        if(root->left==NULL && root->right==NULL && sum+root->val==k)
        {
            return true;
        }
        sum+=root->val;
        bool b1=solve(root->left,k,sum);
        bool b2= solve(root->right,k,sum);
        return b1||b2;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
      
        return solve(root,targetSum,0);
        
    }
};