class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1)
            return ans;
        for(int row=2;row<=numRows;row++){
            vector<int>vec;
            vec.push_back(1);
            for(int col=1;col<(row-1);col++){
                vec.push_back(ans[row-2][col-1]+ans[row-2][col]);
            }
            vec.push_back(1);
            ans.push_back(vec);
        }
        return ans;
    }
};
