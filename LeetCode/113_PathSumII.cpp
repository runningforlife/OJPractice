/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 */

class Solution{
private:
    queue<TreeNode*> q;
    vector<int> vi;
    vector<vector<int> > vvi;
protected:
    void bfs(TreeNode* root, int sum){
        if(root == NULL) return;
        if(root->val == sum && root->left == NULL && root->right == NULL){
            vi.push_back(sum);
            vvi.push_back(sum);
            return;
        }

        vi.push_back(root->val);
        root->val = sum - root->val;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            // now it's the leaf node
            if(node->val == 0 && node->left == NULL && node->right == NULL){
                vvi.push_back(vi);
                vi.pop_back();
            }
            if(node->left != NULL){
                vi.push_back(node->left->val);
                node->left->val =  node->val - node->left->val;
                q.push(node->left);
            }
            if(node->right != NULL){
                vi.push_back(node->left->val);
            }
        }

    }

    void process(TreeNode* root, int sum){
        if(root == NULL) return;

        vi.push_back(root->val);
        if(root->val == sum && root->left == NULL && root->right == NULL){
            vvi.push_back(vi);
            vi.pop_back();
            return;
        }

        if(root->left != NULL) pathSum(root->left,sum-(root->val));
        if(root->right != NULL) pathSum(root->right,sum-(root->val));
        vi.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root,int sum){
        process(root,sum);
        return vvi;
    }
};
