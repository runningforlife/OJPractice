/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> vi;
    // initialize
    vector<vector<int> > vvi;
public:
    void levelTranversal(TreeNode *root, int level){
        if(root == NULL || level < 0) return;

        if(vvi.size() <= level) vvi.push_back(vi);
        vvi[level].push_back(root->val);

        levelTranversal(root->left,level+1);
        levelTranversal(root->right,level+1);
    }

    vector< vector<int> > levelOrderBottom(TreeNode* root){
        if(root == NULL) return vvi;

        levelOrder(root,0);

        reverse(vvi.begin(),vvi.end());

        return vvi;
    }

    vector< vector<int> > levelOrder(TreeNode* root,int level){
        if(root == NULL) return vvi;

        levelTranversal(root,level);

        return vvi;
    }
};
