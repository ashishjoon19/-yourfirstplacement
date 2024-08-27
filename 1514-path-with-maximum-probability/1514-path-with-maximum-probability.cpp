class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int s, int d) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<succProb.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>dist(n,0);
        dist[s]=0;
        priority_queue<pair<double,int>>pq;
        pq.push({1,s});
        while(!pq.empty()){
            pair<double,int>p=pq.top();
            pq.pop();
            double prob=p.first;
            int node=p.second;
            if(node==d)
                return prob;
            if(prob > dist[node])
                dist[node]=prob;
            if(prob < dist[node])
                continue;
            for(auto it:adj[node]){
                if(prob*it.second > dist[it.first])
                    pq.push({prob*it.second,it.first});
            }
        }
        return 0;
    }
};