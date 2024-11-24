class Solution {
    public int maxProfit(int[] prices) {
      int l=0;
      int r=1;
      int pro=0;
    
      while(r<prices.length)
      { 
        if(prices[r]-prices[l]<0)
        {
            r++;
            l++;
        }
        else if(prices[r]-prices[l]>=0)
        {
            while(r<prices.length && prices[r]<prices[l])
            {
                r++;
            }
            pro+=(prices[r]-prices[l]);
            l=r;
            r++;
        }

      }  
    return pro;}
}