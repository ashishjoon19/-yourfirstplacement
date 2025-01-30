class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> visited(n+1, 0);
        int res = 0;
        
        function<int(int)> bfs = [&](int start) {
            queue<int> q;
            unordered_map<int, int> level;
            q.push(start);
            level[start] = 1;
            int maxDepth = 1;
            
            while(!q.empty()){
                int node = q.front(); q.pop();
                for(int nei : adj[node]){
                    if(level.count(nei)){
                        if(abs(level[nei] - level[node]) != 1) 
                            return -1;
                        continue;
                    }
                    level[nei] = level[node] + 1;
                    maxDepth = max(maxDepth, level[nei]);
                    q.push(nei);
                }
            }
            return maxDepth;
        };
        
        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            vector<int> component;
            while(!q.empty()){
                int node = q.front(); q.pop();
                component.push_back(node);
                for(int nei : adj[node]){
                    if(!visited[nei]){
                        visited[nei] = 1;
                        q.push(nei);
                    }
                }
            }
            
            int best = -1;
            for(int node : component){
                int depth = bfs(node);
                if(depth == -1) return -1;
                best = max(best, depth);
            }
            res += best;
        }
        return res;
    }
};
