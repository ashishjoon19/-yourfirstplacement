class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=pow(10,6)+1;
        sort(nums.begin(),nums.end());
        vector<int>freq(maxi,0);
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                freq[abs(nums[i]-nums[j])]++;
            }
        }
        for(int i=0;i<maxi;i++){
            k-=freq[i];
            if(k<=0)
                return i;
        }
        return maxi;
    }
};