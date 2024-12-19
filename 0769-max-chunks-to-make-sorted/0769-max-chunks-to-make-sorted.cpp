class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        string temp = "";
        int count = 0;
        for(int i=0;i<arr.size();i++){
            temp+="0";
        }
        int i=0,j=0;
        int maxi= -1;
        for(int k=0;k<arr.size();k++){
            maxi = max(arr[k],maxi);
            temp[k]='1';
            if(maxi==k){
               string temp2nd = temp.substr(i, j - i + 1);
               string temp3rd(j - i + 1, '1');
                if(temp2nd == temp3rd){
                    i = k + 1;
                    j = k + 1;
                    count++;
                }
            }
        }
        return count;
    }
};