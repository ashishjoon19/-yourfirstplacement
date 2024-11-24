class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int cnt=1,smallest=abs(matrix[0][0]);
        long long sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0)
                    cnt=cnt*(-1);
                smallest=min(smallest,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        if(cnt==-1)
            sum-=(2*smallest);
        return sum;

    }
};