class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto it:nums)
            pq.push(it);

        int res=0;
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            if(a>=k)
                break;
            res++;
            pq.push(((min(a,b)*2)+max(a,b)));
        }
        return res;
    }
};