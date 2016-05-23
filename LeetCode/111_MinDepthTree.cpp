/**
 * Given a binary tree, find its minimum depth.
 */

class Solution{
public:
    int min(int x, int y){
        return x > y ? y : x;
    }
    int minDepth(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;

        if(root->left != NULL && root->right == NULL){
            return minDepth(root->left) + 1;
        }

        if(root->left == NULL && root->right != NULL){
            return minDepth(root->right) + 1;
        }

        return min(minDepth(root->left)+1, minDepth(root->right)+1);
    }
};
