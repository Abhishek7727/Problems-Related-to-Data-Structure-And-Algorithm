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
           //0- camera hai
           //1- wo cover ho raha hai
           //2- need a camera 
           // Aur ye teeno state hum parent ko return karengy Aur parent decide karega ki current m kya karna chahiye matlab need hai camare ki nahi 

           //Aur haa count hum sirf camera ka hi rakhengy 
    
    pair<int,int>solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return {1,0};
        }
          
          auto left=solve(root->left);
          auto right=solve(root->right);

          if(left.first==2 || right.first==2)
          {
            return {0,left.second+right.second+1};
          }

          else if(left.first==0 ||right.first==0)
          return {1,left.second+right.second};
          else
          return {2,left.second+right.second};
    }
    int minCameraCover(TreeNode* root) {
        auto ans=solve(root);
        if(ans.first==2)
        return ans.second+1;
        return ans.second;

    }
};