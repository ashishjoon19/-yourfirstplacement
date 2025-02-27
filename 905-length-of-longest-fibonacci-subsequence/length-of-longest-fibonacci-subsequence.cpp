class Solution {
public:
    int fn(int ind1, int ind2, vector<int>&arr,unordered_map<int,int> &indexMap,vector<vector<int>> &memo){
        int first = arr[ind1];
        int second = arr[ind2];
        int next = first + second;
        if(memo[ind1][ind2]!=-1)return memo[ind1][ind2];
        if(indexMap.find(next)==indexMap.end())return 2;

        int ind3 = indexMap[next];
        return memo[ind1][ind2]=1+fn(ind2,ind3,arr,indexMap,memo);
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> indexMap;
        for(int i=0;i<n;i++){
            indexMap[arr[i]]=i;
        }
        vector<vector<int>> memo(n,vector<int>(n,-1));
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, fn(i,j,arr,indexMap,memo));
            }
        }
        return (ans==2)?0:ans;
    }
};