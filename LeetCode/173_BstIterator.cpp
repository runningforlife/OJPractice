/**
 * Implement an iterator over a binary search tree (BST).
 * Your iterator will be initialized with the root node of a BST.
 */

class BSTIterator {
private:
    //TreeNode* bst;
    vector<int> inorder;
public:
    BSTIterator(TreeNode *root) {
        //this.bst = root;
        inOrderTranveral(root);
        //if(root != NULL) inorder.push_back(-1);
    }

    void inOrderTranveral(TreeNode* root){
        if(root == NULL) return;

        if(root->right != NULL) inOrderTranveral(root->right);
        inorder.push_back(root->val);
        if(root->left != NULL) inOrderTranveral(root->left);
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(inorder.empty()) return false;

        return true;
    }

    /** @return the next smallest number */
    int next() {
        int ret = inorder.back();
        inorder.pop_back();
        return ret;
    }
};
