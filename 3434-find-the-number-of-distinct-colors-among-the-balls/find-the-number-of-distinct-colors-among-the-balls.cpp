class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>nums;
        map<int,int>freq;
        set<int>s;
        vector<int>res;
        for(auto it:queries){
            int num=it[0];//num
            int color=it[1];//color
            if(nums.find(num)!=nums.end()){
                freq[nums[num]]--;
                if(freq[nums[num]]==0)
                    s.erase(nums[num]);
            }
            nums[num]=color;
            freq[color]++;
            s.insert(color);
            res.push_back(s.size());
        }
        return res;
    }
};