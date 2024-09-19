class Solution {
public:
    vector<int>res;
    vector<int> find(string str){
        int n=str.length();
        vector<int>result;
        for(int i=0;i<n;i++){
            if(str[i]=='-'||str[i]=='+'||str[i]=='*'){
                //split
                vector<int>left_res=find(str.substr(0,i));
                vector<int>right_res=find(str.substr(i+1,n));
                for(auto lt:left_res){
                    for(auto rt:right_res){
                        if(str[i]=='*')
                            result.push_back(lt*rt);
                        else if(str[i]=='-')
                            result.push_back(lt-rt);
                        else
                            result.push_back(lt+rt);
                    }
                }
                //no split
            }
        }
        if(result.size()==0){
            result.push_back(stoi(str));
        }
        return result;
    }
    vector<int> diffWaysToCompute(string exp) {
        set<int>s;
        return find(exp);
    }
};