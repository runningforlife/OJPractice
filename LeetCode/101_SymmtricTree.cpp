/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 */

 // reference
class Solution{
public:
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode *p, TreeNode *q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        return (p->val==q->val) && isMirror(p->left,q->right) && isMirror(p->right,q->left);
    }
};

class Solution{
private:
    const int inf = 0x7FFFFFFF;
    vector<int> inorder;
    vector<int> reverseInorder;
public:
    void inOrderTranversal(TreeNode *root){
        if(root != NULL && root->left == NULL && root->right == NULL)
            return;
        if(root == NULL){
            inorder.push_back(inf);
            return;
        }


        inOrderTranversal(root->left);
        inorder.push_back(root->val);
        inOrderTranversal(root->right);
    }
    void reverseInOrderTranversal(TreeNode *root){
        if(root != NULL && root->left == NULL && root->right == NULL)
            return;
        if(root == NULL){
            reverseInorder.push_back(inf);
            return;
        }

        reverseInOrderTranversal(root->right);
        reverseInorder.push_back(root->val);
        reverseInOrderTranversal(root->left);
    }

    bool isSymmetric(TreeNode *root){
        if(root == NULL) return true;

        if((root->left == NULL && root->right == NULL))
            return true;

        inOrderTranversal(root);
        reverseInOrderTranversal(root);

        if(inorder.size() != reverseInorder.size())
            return false;

        vector<int>::iterator it,it1;
        it = inorder.begin();
        it1 = reverseInorder.begin();
        while(it != inorder.end() && it1 != reverseInorder.end()){
            if(*it++ != *it1++) return false;
        }

        return true;
    }
};
