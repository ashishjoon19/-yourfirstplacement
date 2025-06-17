class Solution {
public:
    int minMaxDifference(int num) {
        string str=to_string(num);
        string big=str;
        for(auto it:big){
            if(it!='9'){
                replace(big.begin(),big.end(),it,'9');
                break;
            }
        }
        for(auto it:str){
            if(it!='0'){
                replace(str.begin(),str.end(),it,'0');
                break;
            }
        }
        int res=0;
        for(int i=0;i<str.length();i++){
            res=res*10+(big[i]-str[i]);
        }
        return res;
    }
};