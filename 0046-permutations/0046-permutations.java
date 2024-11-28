class Solution {
    public void bt_permu(ArrayList<Integer> insert,
                         List<List<Integer>> ans,
                         ArrayList<Integer> nums)
                         {
                            if(nums.size()==0)
                            {
                                ans.add(new ArrayList<>(insert));
                                return;
                            }
                            for(int i=0;i<nums.size();i++)
                            {
                                insert.add(nums.get(i));
                                nums.remove(i);
                                bt_permu(insert,ans,nums);
                                nums.add(i,insert.get(insert.size()-1));
                                insert.remove(insert.size()-1);
                            }
                         }
public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans=new ArrayList<>();
        ArrayList<Integer> nu=new ArrayList<>();
        for(int i:nums)
        {
            nu.add(i);
        }
        bt_permu(new ArrayList<>(),ans,nu);
        return ans;
    }
}