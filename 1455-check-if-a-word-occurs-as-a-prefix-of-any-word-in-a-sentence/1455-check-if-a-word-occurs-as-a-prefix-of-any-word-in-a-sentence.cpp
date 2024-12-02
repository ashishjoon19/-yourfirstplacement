class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index=0;
        string word="";

        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' '){
                int j=0;
                for(auto it:word){
                    if(j<searchWord.length() && it==searchWord[j]){
                        j++;
                    }
                    else
                        break;
                }
                if(j==searchWord.length())
                    return index+1;
                word="";
                index++;
            }
            else
                word+=sentence[i];
        }
        int j=0;
        for(auto it:word){
            if(j<searchWord.length() && it==searchWord[j]){
                j++;
            }
            else
                break;
        }
        if(j==searchWord.length())
            return index+1;
        return -1;
    }
};