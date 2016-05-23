#include<cstdio>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};
class Solution{
public:
    int max(int x,int y){
        if(x > y)
            return x;
        return y;
    }
    int maxDepth(TreeNode *root){
        if(root == NULL) return 0;

        return max(maxDepth(root->left) + 1,maxDepth(root->right) + 1);

    }
};

int main(){

    Solution s;

    return 0;
}
