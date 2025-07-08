class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        if(n>=1){
            res.push_back({1});
            if(n==1)
                return res;
        }
        if(n>=2){
            res.push_back({1,1});
            if(n==2){
                return res;
            }
        }
        int idx=2;
        for(int i=3;i<=n;i++){
            vector<int>arr(i);
            arr[0]=1;
            arr[i-1]=1;
            for(int j=1;j<i-1;j++){
                arr[j]=res[i-2][j-1]+res[i-2][j];
            }
            res.push_back(arr);
        }
        return res;
    }
};