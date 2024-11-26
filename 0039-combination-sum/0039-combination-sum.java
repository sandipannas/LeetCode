class Solution {
    List<List<Integer>> og=new ArrayList<>();
    public void bt_sum(int[] can,ArrayList<Integer> gg,int target,int sum,int index)
    {   if(sum>target)
       {
          return;
        }
        if(sum==target)
        {
            og.add(new ArrayList<>(gg));
            return;
        }
         //each element have two choices 
         for(int i=index;i<can.length;i++)
         {//either its yes (the element is included)
         gg.add(can[i]);
         bt_sum(can,gg,target,sum+can[i],i); 
         gg.remove(gg.size()-1);}

        
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        bt_sum(candidates,new ArrayList<>(),target,0,0);
        return og;
    }
}