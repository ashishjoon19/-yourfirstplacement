class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i=0;
        while(i<n){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
            i++;
        }
        for(i=0;i<(n/2);i++){
            for(int j=0;j<n;j++){
                swap(matrix[j][i],matrix[j][n-1-i]);
            }
        }
    }
};