/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> res;
    map<int,vector<int>>m;
    void find(TreeNode *root,int pos){
        if(!root)   return;
        m[pos].push_back(root->val);
        find(root->left,pos-1);
        find(root->right,pos+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)   return res;
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});
        q.push({nullptr,0});
        map<int,vector<int>>m;
        map<int,priority_queue<int,vector<int>,greater<int>>>pq;
        while(!q.empty()){
            TreeNode * node=q.front().first;
            int pos=q.front().second;
            q.pop();
            if(!node){
                for(auto it:pq){
                    int pos=it.first;
                    priority_queue<int,vector<int>,greater<int>>pq=it.second;
                    while(!pq.empty()){
                        m[pos].push_back(pq.top());
                        pq.pop();
                    }
                }
                if(q.empty())   break;
                pq.clear();
                q.push({nullptr,0});
                continue;
            }
            else{
                pq[pos].push(node->val);
                if(node->left)
                    q.push({node->left,pos-1});
                if(node->right)
                    q.push({node->right,pos+1});
            }
        }   
        for(auto it:m){
            res.push_back(it.second);
        }
        return res;
    }
};