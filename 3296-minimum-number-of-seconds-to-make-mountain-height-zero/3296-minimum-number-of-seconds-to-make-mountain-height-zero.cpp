class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pair<long long,pair<int ,int>>,vector<pair<long long,pair<int ,int>>>,greater<pair<long long,pair<int ,int>>>> pq;
        
        for(int i=0;i<workerTimes.size();i++){
            pq.push({workerTimes[i],{workerTimes[i],1}});
        }
        long long ans=0;
        
        for(int i=0;i<mountainHeight;i++){
            long long time = pq.top().first;
            int original = pq.top().second.first;
            int n= pq.top().second.second;
            pq.pop();
            
            ans=time;
            
            pq.push({time+(long long)original*(n+1),{original,n+1}});
            
        }
        return ans;
    }
};