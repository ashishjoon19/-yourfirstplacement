class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int cnt=0;
        for(auto it:arr){
            if(it==0)
                cnt++;
        }
        if(cnt>1)
            return true;
        set<int>s(arr.begin(),arr.end());
        for(auto it:arr){
            if(it%2!=0 || it==0)
                continue;
            it=it/2;
            if(s.find(it)!=s.end())
                return true;
        }
        return false;
    }
};