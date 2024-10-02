class Solution {
public:
    static bool comp(pair<int,int>&p1,pair<int,int>&p2){
        if(p1.first < p2.first)
            return true;
        return false;
    }
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(!n)
            return {};
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
            vec.push_back({arr[i],i});
        
        sort(vec.begin(),vec.end(),comp);

        vector<int>rank(n);
        int c=1;

        rank[vec[0].second]=c;
        for(int i=1;i<n;i++){
            while(vec[i].first == vec[i-1].first){
                rank[vec[i].second]=c;
                i++;
            }
            if(i==n)
                break;
            c++;
            rank[vec[i].second]=c;
        }
        
        return rank;
    }
};