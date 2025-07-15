class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        vow=0
        cons=0
        for it in word :
            if it in 'aeiouAEIOU':
                vow+=1
            elif it.isalpha():
                cons+=1
            elif(it>='0' and it<='9'):
                continue
            else:
                return False
        if(vow>0 and cons>0):
            return True
        return False