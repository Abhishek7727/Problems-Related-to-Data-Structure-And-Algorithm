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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        bool flag=0;
        queue<TreeNode* >q;
        q.push(root);
        while(q.size()>0)
        {
            int n=q.size();
            vector<int>v(n);
          for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
               
                 if(temp->left!=NULL)
                 q.push(temp->left);
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
               if(flag)
                  {
                    v[n-i-1]=temp->val;
                  }
                  else
                  {
                    v[i]=temp->val;
                  }
                  
            }
            flag=1-flag;
            ans.push_back(v);
        }
       return ans;

        
    }
};