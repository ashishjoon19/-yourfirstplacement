class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>vec(51,0);
        for(auto it:ranges){
            for(int i=it[0];i<=it[1];i++)
                vec[i]++;
        }
        for(int i=left;i<=right;i++){
            if(vec[i]==0)
                return false;
        }
        return  true;
    }
};