class Solution {
    public boolean isValid(String word) {
        if(word.length()<3) return false;
        int vow=0,cons=0;
        for(char it :word.toCharArray()){
            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'||it=='A'||it=='E'||it=='I'||it=='O'||it=='U')
                vow++;
            else if(Character.isLetter(it))
                cons++;
            else if(it>='0' && it<='9')
                continue;
            else
                return false;
        }
        if(vow>0 && cons>0)
            return true;
        return false;
    }
}