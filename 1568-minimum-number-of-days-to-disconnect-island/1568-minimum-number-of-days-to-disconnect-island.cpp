class Solution {
public:
    void find(vector<vector<int>>& grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        grid[i][j]=0;
        if(j+1<n && grid[i][j+1]==1)
            find(grid,i,j+1);
        if(i+1<m && grid[i+1][j]==1)
            find(grid,i+1,j);
        if(i-1>=0 && grid[i-1][j]==1)
            find(grid,i-1,j);
        if(j-1>=0 && grid[i][j-1]==1)
            find(grid,i,j-1);
    }
    int islands(vector<vector<int>> grid){
        int res=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    res++;
                    find(grid,i,j);
                }
            }
        }
        return res;
    }
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(islands(grid)!=1)
            return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(islands(grid)!=1)
                        return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};