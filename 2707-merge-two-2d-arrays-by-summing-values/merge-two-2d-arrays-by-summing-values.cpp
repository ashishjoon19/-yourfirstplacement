class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>m;
        vector<vector<int>>res;
        for(auto it:nums1)
            m[it[0]]+=it[1];
        for(auto it:nums2)
            m[it[0]]+=it[1];
        for(auto it:m)
            res.push_back({it.first,it.second});
        return res;
    }
};