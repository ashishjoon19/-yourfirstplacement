class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>arr;
        for(auto it:timePoints){
            int h=(it[0]-'0')*10+(it[1]-'0');
            int m=(it[3]-'0')*10+(it[4]-'0');

            int total=h*60+m;
            if(total > 720)
                total=-(1440-total);
            arr.push_back(total);
        }
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        for(int i=0;i+1<arr.size();i++){
            int diff=abs(arr[i]-arr[i+1]);
            if(diff > 720)
                diff=1440-diff;
            if(diff < mini)
                mini=diff;
        }

        int diff=INT_MAX;
        if(arr.size() > 1)
            diff=abs(arr[0]-arr[arr.size()-1]);
        else
            return mini;
        if(diff > 720)
            diff=1440-diff;
        if(diff < mini)
            mini=diff;
        return mini;
    }
};