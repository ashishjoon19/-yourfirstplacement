class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int tp=q.front();
            q.pop();
            for(auto it:adj[tp]){
                indegree[it]--;
                if(!indegree[it])
                    q.push(it);
            }
        }
        for(auto it:indegree)
            if(it)  return false;
        return true;
    }
};