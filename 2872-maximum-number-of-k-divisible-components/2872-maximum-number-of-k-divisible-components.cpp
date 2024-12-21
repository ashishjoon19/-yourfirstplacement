class Solution {
    int count = 0;
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> visited(n, 0);
        dfs(0, adj, k, visited, values);
        return count;
    }

    long long dfs(int curr, vector<vector<int>> &adj, int k, vector<int> &visited, vector<int>& values){
        long long sum = 0;
        visited[curr] = 1;
        for(auto child : adj[curr]){
            if(visited[child]) continue;
            sum += dfs(child, adj, k, visited, values);
        }
        if((sum + values[curr]) % k == 0) count++;
        return sum + values[curr];
    }
};