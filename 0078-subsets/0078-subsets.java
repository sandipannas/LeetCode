class Solution {
    List<List<Integer>> og=new ArrayList<>();
    public void bt_sub(int[] nums,ArrayList<Integer> gg,int i)
    {
        if(i>=nums.length)
        {
            og.add(gg);
            return;
        }

        //two choices

        //eiter a yes
        ArrayList<Integer> nnn=(ArrayList)gg.clone();
        nnn.add(nums[i]);
        bt_sub(nums,nnn,i+1);
        

        //or a no
        bt_sub(nums,gg,i+1);
    }
    public List<List<Integer>> subsets(int[] nums) {
        bt_sub(nums,new ArrayList<>(),0);
        return og;
    }
}