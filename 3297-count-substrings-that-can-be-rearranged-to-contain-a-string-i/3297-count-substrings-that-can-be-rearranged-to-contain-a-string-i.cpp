class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        map<char,int>mapi;
        int n=word1.size();
        for(auto it:word2)
            mapi[it]++;
        map<char,int>m=mapi;
        map<char,int>curr;
        int i=0,j=0;
        long long res=0;
        while(j<n){
            if(mapi.find(word1[j])!=mapi.end())
                curr[word1[j]]++;
            if(m.find(word1[j])!=m.end()){
                m[word1[j]]--;
                if(!m[word1[j]]){
                    m.erase(word1[j]);
                    if(m.size()==0){
                        while(i<=j){
                            res+=1+(n-1)-j;
                            if(curr.find(word1[i])!=curr.end()){
                                curr[word1[i]]--;
                                if(curr[word1[i]] < mapi[word1[i]]){
                                    m[word1[i]]++;
                                    i++;
                                    break;
                                }
                            }
                            i++;
                        }
                    }
                }
            }
            j++;
        }
        return res;
    }
};