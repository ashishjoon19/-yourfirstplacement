class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:intervals){
            bool flag=false;
            if(!pq.empty() && pq.top() < it[0]){
                pq.pop();
                pq.push(it[1]);
                flag=true;
            }
            if(!flag)
                pq.push(it[1]);
        }
        return pq.size();
    }
};