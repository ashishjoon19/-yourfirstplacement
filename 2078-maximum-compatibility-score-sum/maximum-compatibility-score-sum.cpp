class Solution {
private:
    int n;
    int find(vector<vector<int>>& students, vector<vector<int>>& mentors,int idx,set<int>&s){
        if(idx>=n) return 0;
        int sum=0,res=0;
        for(int i=0;i<n;i++){
            //calculate sum;
            if(s.find(i)!=s.end()) continue;

            for(int j=0;j<students[i].size();j++){
                if(students[idx][j]==mentors[i][j])   sum++;
            }
            s.insert(i);
            sum+=find(students,mentors,idx+1,s);
            res=max(sum,res);
            sum=0;
            s.erase(i);
        }       
        return res;
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        set<int>s;
        n=students.size();
        return find(students,mentors,0,s);
    }
};