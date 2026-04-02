class Solution {
public:
bool res=false;
void solve(TreeNode* root,int k,int sum)
    {
        if(root==NULL)
        return ;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL )
        {
            if(k==sum)
            res= true;
            return ;
        }
        
        solve(root->left,k,sum);
        solve(root->right,k,sum);
        return ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
       solve(root,targetSum,0);
        return res;
        
        
    }
};