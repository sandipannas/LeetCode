class Solution {
    public boolean check(int[] nums) {
        int n=nums.length,holder=0;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]<nums[i-1])
            {
              holder=i;
              
            }
            
            
        }
        if(holder==0)
        {
            return true;
        }
        for(int i=0;i<holder-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
              return false;
            }
        }
        for(int i=holder;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
              return false;
            }
        }
        if((holder!=0 && nums[holder-1]<nums[n-1]) || (nums[0]<nums[n-1]))
        {
            return false;
        }
        return true;
    }
}