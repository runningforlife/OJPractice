/**
 * determine whether a binary tree is height-balanced
 */

class Solution{
public:
    int max(int x,int y){
        return x > y ? x : y;
    }
    int getTreeHeight(TreeNode* root){
        if(root == NULL) return 0;

        return max(getTreeHeight(root->left) + 1,getTreeHeight(root->right) + 1);
    }
    bool isBalanced(TreeNode* root){
        if(root == NULL) return true;

        int leftHeight = getTreeHeight(root->left);
        int rightHeight = getTreeHeight(root->right);
        if(leftHeight > rightHeight + 1 || rightHeight > leftHeight + 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
