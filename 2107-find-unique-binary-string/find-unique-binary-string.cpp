class Solution {
private:
    set<string>s;
    string result;
    void find(string str,int &n,int &flag){
        if(flag) return;
        if(str.length()==n){
            if(s.find(str)==s.end()){
                result=str;
                flag=1;
            }
            return;
        }
        find(str+'0',n,flag);
        find(str+'1',n,flag);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        for(auto it:nums)
            s.insert(it);
        int flag=0;
        find("",n,flag);
        return result;
    }
};