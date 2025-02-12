class Solution {
private:
    int find_sum(int num){
        int sum=0;
        while(num){
            sum += num%10;
            num/=10;
        }
        return sum;
    }
    static bool comp(int a,int b){
        return a>b;
    }
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>m;
        int n=nums.size();
        for(auto it:nums){
            m[find_sum(it)].push_back(it);
        }
        int res=-1;
        for(auto it:m){
            int sum=it.first;
            vector<int>vec(it.second);
            if(vec.size()<2)
                continue;
            sort(vec.begin(),vec.end(),comp);
            res=max(res,(vec[0]+vec[1]));
        }
        return res;
    }
};