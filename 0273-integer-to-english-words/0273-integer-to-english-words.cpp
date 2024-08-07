class Solution {
public:
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string res=find(num%1000);
        num/=1000;
        vector<string> paisa={"Thousand","Million","Billion"};
        for(int i=0;i<3;i++){
            if(num % 1000!=0)
                res=find(num%1000)+paisa[i]+" "+res;
            num/=1000;
        }
        return res.substr(0,res.size()-1);
    }
    string find(int num){
        string digit[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine"};
        string teen[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string ten[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string result = "";
        if (num > 99) {
            result += digit[num / 100] + " Hundred ";
        }
        num %= 100;
        if (num < 20 && num > 9) {
            result += teen[num - 10] + " ";
        } else {
            if (num >= 20) {
                result += ten[num / 10] + " ";
            }
            num %= 10;
            if (num > 0) {
                result += digit[num] + " ";
            }
        }
        return result;
    }
};