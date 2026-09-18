class Solution:
    def countSeniors(self, details: List[str]) -> int:
        count=0
        for s in details:
            if s[11:13:1]>"60" :
                count+=1
        return count 
        