class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res=-INT_MAX;
        set<int>s;
        for(auto it:nums){
            res=max(res,it);
            if(it<=0)
                continue;
            s.insert(it);
        }
        if(s.size()==0){
            return res;
        }
        res=0;
        for(auto it:s)
            res+=it;
        return res;
    }
};