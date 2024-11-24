class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        HashMap<Integer,Integer> gg=new HashMap<>();
        int min=Integer.MIN_VALUE;
        for(int i=0;i<wall.size();i++)
        {   List<Integer> sei=wall.get(i);
            int gap=0;
            for(int j=0;j<sei.size();j++)
            {   gap+=sei.get(j);
                if(gg.containsKey(gap))
                {
                    gg.put(gap,gg.get(gap)+1);
                    
                }
                else
                {
                    gg.put(gap,1);
                }
                if(j+1!=sei.size())
                {
                min=Math.max(gg.get(gap),min);
                }

            }
        }
        System.out.println(gg);
        if(min==Integer.MIN_VALUE)
        {
            return wall.size();
        }
    return wall.size()-min;}
}