class Solution {
private:
    queue<TreeNode*>q;
    int depth;
    map<TreeNode*,vector<TreeNode*>>adj;
    void find_deepest_leaf_nodes(TreeNode* root,int cnt){
        if(!root) return;

        if(root->left==NULL && root->right==NULL){
            if(depth < cnt){
                queue<TreeNode*>temp;
                q=temp;
                q.push(root);
                depth=cnt;
            }

            else if(depth == cnt){
                q.push(root);
            }
            return;
        }
        if(root->left){
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
        }
        if(root->right){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
        }

        find_deepest_leaf_nodes(root->left,cnt+1);
        find_deepest_leaf_nodes(root->right,cnt+1);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //tree to graph
        depth=0;
        adj[root]={};
        find_deepest_leaf_nodes(root,0);
        map<TreeNode*,int>vis;
        for(auto it:adj)
            vis[it.first]=0;
        int n=q.size();
        while(!q.empty()){
            if(q.size()==1) break;
            TreeNode* top=q.front();
            vis[top]=-1;
            q.pop();
            for(auto it:adj[top]){
                if(vis[it]!=-1){
                    q.push(it);
                    vis[it]++;
                }
                if(vis[it]==n){
                    return it;
                }
            }
        }
        return q.front();
    }
};