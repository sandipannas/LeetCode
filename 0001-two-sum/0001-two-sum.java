class Solution {
    public int[] twoSum(int[] nums, int target) {
        
      HashMap<Integer,Integer> gg=new HashMap<>();
        
      for(int i=0;i<nums.length;i++)
      {
        if(gg.containsKey(target-nums[i]))
        {
            return new int[]{gg.get(target-nums[i]),i};
        }
        else
        {
            gg.put(nums[i],i);
        }
      }  
    return new int[2];}
}