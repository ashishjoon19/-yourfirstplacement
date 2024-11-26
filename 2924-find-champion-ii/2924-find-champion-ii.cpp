class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int res=-1;
        vector<bool>is_true(n,true);
        vector<vector<int>>graph(n);
        for(auto it:edges)
            graph[it[0]].push_back(it[1]);

        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                is_true[it]=false;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(is_true[i]){
                res=i;
                cnt++;
            }
        }
        return cnt==1?res:-1;
    }
};