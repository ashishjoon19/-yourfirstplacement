class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it:nums)
            pq.push(it);
        long long sum=0;
        while(k--){
            int num=pq.top();
            sum+=num;
            pq.pop();
            if(num%3==0)
                pq.push(num/3);
            else
                pq.push((num/3)+1);
        }
        return sum;
    }
};