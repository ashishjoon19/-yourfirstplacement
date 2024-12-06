class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum=0,res=0;
        set<int>Banned;
        for(auto it:banned)
            Banned.insert(it);
            
        for(int i=1;i<=n;i++){
            if(sum+i > maxSum){
                break;
            }
            else{
                if(Banned.find(i)==Banned.end()){
                    sum+=i;
                    res++;
                }
            }
        }
        return res;
    }
};