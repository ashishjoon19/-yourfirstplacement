class Solution {
private:
    vector<long long>res;
    void find(TreeNode* root){
        if(!root)
            return;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        long long sum=0;
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node==nullptr){
                res.push_back(sum);
                if(q.empty())
                    break;
                q.push(nullptr);
                sum=0;
            }
            else{
                sum+=node->val;
                if(node->left!=nullptr)
                    q.push(node->left);
                if(node->right!=nullptr)
                    q.push(node->right);
            }
        }
    }
    static bool comp(long long &a,long long &b){
        if(a > b)
            return true;
        return false;
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        find(root);
        sort(res.begin(),res.end(),comp);
        if(res.size()<k)
            return -1;
        return res[k-1];
    }
};