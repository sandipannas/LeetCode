class Solution {
    public boolean containsDuplicate(int[] nums) {
        
      // less optimized (brute force)

       /*
        int n=nums.length;
        Arrays.sort(nums);
        for(int i=0;i+1<n;i++)
        {
            if(nums[i]==nums[i+1])
            {
                return true;
            }

        }
        return false; 
        */
        
        // more optimized
        
        Set<Integer> sack=new HashSet<>();
        for(int i:nums)
        {
            if(sack.contains(i))
            {
                return true;
            }
            sack.add(i);
        }
        return false;
    }
}