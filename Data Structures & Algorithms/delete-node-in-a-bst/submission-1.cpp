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
    TreeNode* findMin(TreeNode* node)
    {
        while(node->left)
            node = node->left;

        return node;
    };

    TreeNode* deleteNode(TreeNode* root, int key) {
    // 1. Find node

    // 2. No child
    //    → return nullptr

    // 3. One child
    //    → return child

    // 4. Two children
    //    → replace with successor
    //    → delete 
    

    // Inorder Successor
    //     Smallest value in right subtree.

    // Inorder Predecessor
    //     Largest value in left subtree.

    if(root==nullptr)
    return nullptr;

    if(key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->val)
    {
           root->right = deleteNode(root->right, key);     
    }
    else // key == root->val
    {
        // case 1 and 2
        if(root->left == nullptr)
        {
            return root->right;
        }

        if(root->right == nullptr)
        return root->left;

        //case3 

        TreeNode* successor = findMin(root->right);
        root->val = successor->val;

        root->right  = deleteNode(root->right, successor->val);

    }

    return root;
    }
};