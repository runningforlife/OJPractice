/**
 * for BST only
 * The lowest common ancestor is defined
 * between two nodes v and w as the lowest node in T that has both v and w
 * as descendants (where we allow a node to be a descendant of itself)
 */

class Solution{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root,TreeNode *p, TreeNode *q){
        if(root == NULL || root->val == p->val || root->val == q->val) return root;
        if((root->val > p->val && root->val < q->val) || (root->val > q->val && root->val < p->val))
            return root;

        if(root->val > p->val && root->val > q->val)
            lowestCommonAncestor(root->left,p,q);
        else
            lowestCommonAncestor(root->right,p,q);

    }
};
