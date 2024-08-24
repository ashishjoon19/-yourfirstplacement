class Solution {
    public String nearestPalindromic(String n) {
        boolean even=n.length()%2==0;
        int mid=n.length()/2;
        if(even) mid-=1;
        long left= Long.parseLong(n.substring(0,mid+1));
        List<Long> cases=new ArrayList<>();
        cases.add(palindrome(left,even));
        cases.add(palindrome(left+1,even));
        cases.add(palindrome(left-1,even));
        cases.add((long)Math.pow(10,n.length()-1)-1);
        cases.add((long)Math.pow(10,n.length())+1);
        long diff=Integer.MAX_VALUE;
        long num=Long.parseLong(n);
        long result=0;
        for(long it:cases){
            if(it==num) continue;
            if(Math.abs(it-num) < diff){
                diff=Math.abs(it-num);
                result=it;
            }
            else if(Math.abs(it-num) ==diff){
                result=Math.min(it,result);
            }
        }
        return String.valueOf(result);
    }
    long palindrome(long left,boolean even){
        long res=left;
        if(!even) left/=10;
        while(left>0){
            res=res*10+left%10;
            left/=10;
        }
        return res;
    }
}