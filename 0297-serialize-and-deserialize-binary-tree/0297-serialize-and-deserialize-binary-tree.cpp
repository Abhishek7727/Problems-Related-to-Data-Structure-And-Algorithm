/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode* root,string & str)
    {
        if(root==NULL)
        {
            str+="N,";
            return;
        }
        str+=to_string(root->val)+",";
        preorder(root->left,str);
        preorder(root->right,str);

        
    }
    string serialize(TreeNode* root) {
        string s="";
        preorder(root,s);
        return s;
    }
    TreeNode* build(vector<string>&arr,int &ind)
    {
        if(arr[ind]=="N")
        { 
            ind++;
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(arr[ind]));
        ind++;
        root->left=build(arr,ind);
        root->right=build(arr,ind);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>arr;
        string temp="";
        for(char ch:data)
        {
            if(ch==',')
            {
                arr.push_back(temp);
                temp="";
            }
            else
            temp+=ch;
        }
        int ind=0;
        TreeNode* root=build(arr,ind);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));