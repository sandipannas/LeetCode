class Solution:
    def maxDifference(self, s: str) -> int:
        small_odd=float('inf')
        big_odd=0

        small_even=float('inf')
        big_even=0

        map=defaultdict(int)

        for c in s:
            map[c]+=1
        
        for key,value in map.items() :
            if value%2==0 :
                small_even=min(small_even,value)
                big_even=max(big_even,value)
            else :
                small_odd=min(small_odd,value)
                big_odd=max(big_odd,value)
        
        return max(small_odd-big_even,big_odd-small_even)