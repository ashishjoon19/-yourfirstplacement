class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*>q;
        vector<vector<int>>res;
        vector<int>vec;
        if(!root)   return res;
        q.push_back(root);
        q.push_back(nullptr);
        int flag=0;
        while(!q.empty()){
            if(!flag){
                TreeNode* node=q.front();
                q.pop_front();
                if(!node){
                    flag=(flag+1)%2;
                    res.push_back(vec);
                    vec.clear();
                    if(q.empty())   return res;
                    q.push_front(nullptr);
                    continue;
                }
                vec.push_back(node->val);
                if(node->left)
                    q.push_back(node->left);
                if(node->right)
                    q.push_back(node->right);
            }
            else{
                TreeNode* node=q.back();
                q.pop_back();
                if(!node){
                    flag=(flag+1)%2;
                    res.push_back(vec);
                    vec.clear();
                    if(q.empty())   return res;
                    q.push_back(nullptr);
                    continue;
                }
                vec.push_back(node->val);
                if(node->right)
                    q.push_front(node->right);
                if(node->left)
                    q.push_front(node->left);
            }
        }
        return res;
    }
};