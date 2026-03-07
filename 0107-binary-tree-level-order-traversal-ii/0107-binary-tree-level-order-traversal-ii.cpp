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
   int depth(TreeNode* root)
   {
    if(root==NULL)
    return 0;
    return 1+max(depth(root->left),depth(root->right));

   }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d=depth(root);
        vector<vector<int>>ans(d,vector<int>({}));
        if(root==NULL)
        return ans;
     
        queue<TreeNode*> q;
        //int idx=0;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
          //  cout<<n<<" ";
            vector<int>v;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);

                v.push_back(temp->val);
            }
            ans[d-1]=v;
            d--;

           

        }
        return ans;

        
    }
};