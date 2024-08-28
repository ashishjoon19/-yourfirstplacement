class Solution {
public:
    int m1,n1,m2,n2,res;
    void find(int r,int c,vector<vector<int>>& grid1, vector<vector<int>>& grid2,int &flag){
        grid2[r][c]=2;
        if(r+1 < m2 && grid2[r+1][c]==1){
            if(grid1[r+1][c]!=1){
                flag=1;
            }
            find(r+1,c,grid1,grid2,flag);
        }
        if(r-1 >=0 && grid2[r-1][c]==1){
            if(grid1[r-1][c]!=1){
                flag=1;
            }
            find(r-1,c,grid1,grid2,flag);
        }
        if(c+1 < n2 && grid2[r][c+1]==1){
            if(grid1[r][c+1]!=1){
                flag=1;
            }
            find(r,c+1,grid1,grid2,flag);
        }
        if(c-1 >=0 && grid2[r][c-1]==1){
            if(grid1[r][c-1]!=1){
                flag=1;
            }
            find(r,c-1,grid1,grid2,flag);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m1=grid1.size();
        n1=grid1[0].size();
        m2=grid2.size();
        n2=grid2[0].size();
        res=0;
        for(int i=0;i<m2;i++){
            for(int j=0;j<n2;j++){
                if(grid2[i][j]==1 && grid1[i][j]==1){
                    int flag=0;
                    find(i,j,grid1,grid2,flag);
                    if(flag==0)
                        res++;
                }
            }
        }
        return res;
    }
};