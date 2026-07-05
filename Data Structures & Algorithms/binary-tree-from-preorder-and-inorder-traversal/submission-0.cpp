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

    unordered_map<int,int> mp;
    int pre_index =0;
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right)
    {
        if(left >  right)
        return nullptr;

        int root_val = preorder[pre_index++];
        
        TreeNode* root = new TreeNode(root_val);

        int mid = mp[root_val];

        root->left = build(preorder, inorder, left, mid-1);

        root->right = build(preorder, inorder, mid+1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, inorder.size()-1);
    }
};
