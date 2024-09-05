class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=0;
        for(auto it:rolls)
            sum+=it;
        sum=mean*(m+n)-sum;

        int el=sum/n;
        int rem=sum%n;
        vector<int>res(n,el);
        if(res[0] < 1 || res[0] >6)
            return {};
        if(rem < 1)
            return res;
        for(int i=0;i<n;i++){
            res[i]++;
            rem--;
            if(res[i] > 6)
                return {};
            if(rem==0)
                break;
        }
        return res;
    }
};