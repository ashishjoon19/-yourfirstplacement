class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string>supp;
        map<string,int>index;
        map<string,vector<string>>graph;
        map<string,int>indegree;
        queue<string>q;
        int n=recipes.size();
        
        for(auto it:supplies)
            supp.insert(it);

        for(auto it:recipes){
            indegree[it]=0;
            graph[it]={};
        }
        for(int i=0;i<n;i++){
            index[recipes[i]]=i;
            for(auto it:ingredients[i]){
                if(supp.find(it)==supp.end() && graph.find(it)!=graph.end()){
                    graph[it].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }


        for(auto it:graph){
            if(indegree[it.first]==0)
                q.push(it.first);
        }
        vector<string>res;
        while(!q.empty()){
            string top=q.front();
            q.pop();
            int ind=index[top];
            int flag=0;
            for(auto it:ingredients[ind]){
                if(supp.find(it)==supp.end()){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                supp.insert(top);
                res.push_back(top);
            }

            for(auto it:graph[top]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return res;
    }
};