class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n=a.size();
        set<vector<int>>s;
        sort(a.begin(),a.end());
        for(int i=0;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                long long sum = target-(long long)(a[i]+a[j]);
                int temp_i=j+1;
                int temp_j=n-1;
                while(temp_i < temp_j){
                    if(a[temp_i] + a[temp_j] < sum)
                        temp_i++;
                    else if(a[temp_i] + a[temp_j] > sum)
                        temp_j--;
                    else{
                        vector<int>temp;
                        temp.push_back(a[i]);
                        temp.push_back(a[j]);
                        temp.push_back(a[temp_i]);
                        temp.push_back(a[temp_j]);
                        s.insert(temp);
                        temp_i++;
                        temp_j--;
                    }
                }
            }
        }
        vector<vector<int>>res;
        for(auto it:s){
            res.push_back(it);
        }
        return res;
    }
};