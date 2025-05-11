class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int flag=0;
        for(auto it:arr){
            if(it%2!=0){
                flag++;
                if(flag==3)
                    return true;
            }
            else
                flag=0;
        }
        return false;
    }
};