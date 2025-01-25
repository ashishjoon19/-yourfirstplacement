class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>vec(nums);
        sort(vec.begin(),vec.end());
        int group=0;
        map<int,queue<int>>m;
        map<int,int>gr;
        m[group].push(vec[0]);
        gr[vec[0]]=group;
        for(int i=1;i<n;i++){
            if(abs(vec[i-1]-vec[i]) <= limit){
                m[group].push(vec[i]);
                gr[vec[i]]=group;
            }
            else{
                group++;
                m[group].push(vec[i]);
                gr[vec[i]]=group;
            }
        }
        for(int i=0;i<n;i++){
            group=gr[nums[i]];
            vec[i]=m[group].front();
            m[group].pop();
        }
        return vec;
    }
};