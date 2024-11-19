class Solution {
    public boolean containsDuplicate(int[] nums) {
        //taking a hashset which can only store unique values
        Set<Integer> sack=new HashSet<>();
        //traversing the array
        for(int i:nums)
        {   //checking if set already contains the number or not 
            if(sack.contains(i))
            {   //if yes it contains then its a duplicate
                return true;
            }
            //if not then add the number to the set
            sack.add(i);
        }
        //if it passes through whole array then there is no duplicates
        return false;
    }
}
