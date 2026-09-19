class Solution:
    def maxDifference(self, s: str) -> int:

        big_odd=0
        small_even=float('inf')

        map=defaultdict(int)

        for c in s:
            map[c]+=1
        
        for key,value in map.items() :
            if value%2==0 :
                small_even=min(small_even,value)
            else :
                big_odd=max(big_odd,value)
        
        return big_odd-small_even