class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>freq;
        int n=fruits.size();
        if(n==1 || n==0)
            return n;
        int res=0,i;
        int left=0;
        for(i=0;i<n;i++){
            freq[fruits[i]]++;
            while(freq.size()>2){
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0)
                {
                    freq.erase(fruits[left]);
                }
                left++;
            }
            res=max(res,i-left+1);
        }
        return res;
    }
};