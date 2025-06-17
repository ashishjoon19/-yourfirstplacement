class Solution {
public:
    int maxDiff(int num) {
        string str=to_string(num);
        // cout<<str;
        string big=str;
        for(auto it:str){
            if(it!='9'){
                replace(big.begin(),big.end(),it,'9');
                break;
            }
        }
        if(str[0]!='1'){
            char ch=str[0];
            replace(str.begin(),str.end(),ch,'1');
        }
        else{
            for(auto it:str){
                if(it>'1'){
                    replace(str.begin(),str.end(),it,'0');
                    break;
                }
            }
        }
        int res=0;
        for(int i=0;i<str.length();i++){
            res=res*10+(big[i]-str[i]);
        }
        cout<<big<<endl<<str;

        return res;//555 9 123456 123 111 1101057
    }
};