class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        if(!root)
            return res;
        int maxi = (root->val);
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node!=NULL){
                maxi=maxi>(node->val)?maxi:(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            else{
                res.push_back(maxi);
                if(q.empty())
                    break;
                maxi=(q.front()->val);
                q.push(NULL);
            }
        }
        return res;
    }
};