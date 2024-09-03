class Solution {
public:
    int getLucky(string s, int k) {
        string str="";
        for(auto it:s){
            str+=to_string(it-'a'+1);
        }
        long long sum=0;
        while(k--){
            sum=0;
            for(auto it:str)
                sum+=it-'0';
            str=to_string(sum);
        }
        return sum;
    }
};