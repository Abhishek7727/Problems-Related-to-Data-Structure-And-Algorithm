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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        return NULL;
        
        if(root->val>key)
         root->left = deleteNode(root->left,key);
        
        else if(root->val<key)
        root->right = deleteNode(root->right,key);

        else
        {

            if(root->left==NULL)
            {
                return root->right;
            }
            if(root->right==NULL)
            return root->left;

            TreeNode* next=root->right;
            while(next->left!=NULL)
            {
                next=next->left;
            }
            root->val=next->val;
            root->right=deleteNode(root->right,next->val);
        }

        return root;
    }
};