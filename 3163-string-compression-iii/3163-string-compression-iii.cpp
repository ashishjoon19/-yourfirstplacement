class Solution {
public:
    string compressedString(string word) {
        string res="";
        int cnt=1;
        int i=1;
        int flag=0;
        for(i=1;i<word.length();i++){
            if(word[i]==word[i-1]){
                cnt++;
                flag=0;
                if(cnt==9){
                    cnt=0;
                    res+=to_string(9)+word[i];
                    flag=1;
                }
            }
            else{
                if(cnt)
                    res+=to_string(cnt)+word[i-1];
                cnt=1;
                flag=0;
            }
        }
        if(!flag)
            res+=to_string(cnt)+word[i-1];
        return res;
    }
};