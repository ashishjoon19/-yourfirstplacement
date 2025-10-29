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
    map<int,vector<int>>m;
    map<int,int>vis;
    vector<int>res;
    void dfs(int target,int k){
        vis[target]=1;
        if(k==0){
            res.push_back(target);
            vis[target]=0;
            return;
        }
        if(m.find(target)==m.end()){
            vis[target]=0;
            return;
        }
        for(auto it:m[target]){
            if(!vis[it])
                dfs(it,k-1);
        }
        vis[target]=0;
    }
    void make_graph(TreeNode *root){
        if(!root)   return;
        if(root->left){
            m[root->val].push_back(root->left->val);
            m[root->left->val].push_back(root->val);
        }
        if(root->right){
            m[root->val].push_back(root->right->val);
            m[root->right->val].push_back(root->val);
        }
        make_graph(root->left);
        make_graph(root->right);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        make_graph(root);
        dfs(target->val,k);
        return res;
    }
};