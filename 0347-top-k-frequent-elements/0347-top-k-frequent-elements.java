class Solution {
    public int[] topKFrequent(int[] nums, int k) {
     HashMap<Integer,Integer> gg=new HashMap<>();
     ArrayList<Integer> hh[]=new ArrayList[nums.length];
     for(int i:nums)
     {
        if(gg.containsKey(i))
        {
            gg.put(i,gg.get(i)+1);
        }
        else
        {
            gg.put(i,1);
        }
        
     } 
     for(int i:gg.keySet())
     {  if(hh[gg.get(i)-1]==null){
        hh[gg.get(i)-1]=new ArrayList<>();
     }
        hh[gg.get(i)-1].add(i);
        
     }
     ArrayList<Integer> jj=new ArrayList<>();
     for(int i=nums.length-1;i>-1;i--)
     {  if(hh[i]!=null)
     {
        jj.addAll(hh[i]);
     }
     
        
     }
     int[] arr=new int[k]; 
     for(int i=0;i<k;i++)
     {
        arr[i]=jj.get(i);
     }
     
     
   return arr; }
}