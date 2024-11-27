// class Solution {
// public:
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         // priority_queue<pair<int,int>>pq;
//         map<int,vector<int>>adj;
//         for(int i=0;i<n-1;i++){
//             adj[i].push_back(i+1);
//         }
//         vector<int>res;
//         for(auto it:queries){
//             int from=it[0];
//             int to=it[1];
//             adj[from].push_back(to);
//             priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
//             pq.push({0,0});
//             while(!pq.empty()){
//                 pair<int,int>p=pq.top();
//                 pq.pop();
//                 int dist=p.first;
//                 int node=p.second;
//                 if(node == n-1)
//                 {    res.push_back(dist);
//                     break;
//                 }
//                 for(auto it:adj[node]){
//                     pq.push({dist+1,it});
//                 }
//             }
//         }
//         return res;
//     }
// };#include <vector>
#include <queue>
#include <map>
#include <limits>
#include <utility>

class Solution {
public:
    std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries) {
        std::map<int, std::vector<int>> adj;
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        std::vector<int> res;
        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];
            adj[from].push_back(to);

            std::vector<int> dist(n, std::numeric_limits<int>::max());
            dist[0] = 0;

            using pii = std::pair<int, int>;
            std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
            pq.push({0, 0});

            while (!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();

                if (d > dist[node]) {
                    continue;
                }

                for (int neighbor : adj[node]) {
                    if (dist[node] + 1 < dist[neighbor]) {
                        dist[neighbor] = dist[node] + 1;
                        pq.push({dist[neighbor], neighbor});
                    }
                }
            }
            res.push_back(dist[n - 1]);
        }

        return res;
    }
};
