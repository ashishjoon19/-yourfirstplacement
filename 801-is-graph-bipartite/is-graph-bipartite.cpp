class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>gp(n,-1);
        gp[0]=0;
        int group=0;
        for(int node=0;node<n;node++){
            if(node!=0)
                group=gp[node];
            for(auto it:graph[node]){
                if(gp[it]==-1){
                    gp[it]=1-group;
                }
                else{
                    if(gp[it]==group)
                        return false;
                }
            }
        }
        return true;
    }
};