/**
 * Given a binary tree and a sum,
 * determine if the tree has a root-to-leaf path such that
 * adding up all the values along the path equals the given sum.
 */

/*if(root->val == sum){
            return true;
        }

        return (hasPathSum(root->left,sum - (root->val)) || hasPathSum(root->right,sum - (root->val)));
    }*/
class Solution{

public:
    bool hasPathSum(TreeNode* root, int sum){
        if(root == NULL) return false;
        if(root->val == sum && root->left == NULL && root->right == NULL) return true;

        return hasPathSum(root->left,sum - (root->val)) || hasPathSum(root->right,sum - (root->val));
    }
};
