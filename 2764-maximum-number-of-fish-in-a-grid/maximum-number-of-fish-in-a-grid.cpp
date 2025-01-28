class Solution {
private:
    int m;
    int n;
    int dfs(vector<vector<int>>& grid,int i,int j){
        int val=grid[i][j];
        grid[i][j]=0;
        if(i+1 < m && grid[i+1][j]!=0)
            val+=dfs(grid,i+1,j);
        if(i-1 >= 0 && grid[i-1][j]!=0)
            val+=dfs(grid,i-1,j);
        if(j+1 < n && grid[i][j+1]!=0)
            val+=dfs(grid,i,j+1);
        if(j-1 >= 0 && grid[i][j-1]!=0)
            val+=dfs(grid,i,j-1);
        
        return val;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    res=max(res,dfs(grid,i,j));
                }
            }
        }
        return res;
    }
};