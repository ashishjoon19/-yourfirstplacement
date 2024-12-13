class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i].first=nums[i];
            vec[i].second=i;
        }
        set<int>marked;
        sort(vec.begin(),vec.end());
        long long res=0;
        for(auto it:vec){
            if(marked.find(it.second)==marked.end()){
                res+=it.first;
                marked.insert(it.second);
                if((it.second-1) >=0)
                    marked.insert(it.second-1);
                if((it.second+1)<n)
                    marked.insert(it.second+1);
            }
        }
        return res;
    }
};