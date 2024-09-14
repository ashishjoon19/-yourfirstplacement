class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>result;
        vector<int>pre_xor;
        int sum=0;
        for(auto it:arr){
            sum^=it;
            pre_xor.push_back(sum);
        }

        for(auto it:queries){
            if(it[0]==0){
                result.push_back(pre_xor[it[1]]);
                continue;
            }
            result.push_back(pre_xor[it[1]]^pre_xor[it[0]-1]);
        }
        return result;
    }
};