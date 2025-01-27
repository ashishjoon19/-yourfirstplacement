class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        queue<int>q;
        vector<int>vec;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<unordered_set<int>> pre(n);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                pre[v].insert(u);
                pre[v].insert(pre[u].begin(), pre[u].end());
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        vector<bool> ans(queries.size());
        for(int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0], v = queries[i][1];
            ans[i] = pre[v].find(u) != pre[v].end();
        }

        return ans;
    }
};