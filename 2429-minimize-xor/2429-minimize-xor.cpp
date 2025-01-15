class Solution {
public:
    int sett(int num)
    {
        int count=0;
        for(int i=31;i>=0;i--)
        {
            if((num&(1<<i))!=0)
            {
                count++;
            }
        }
        return count;
        
    }
    int minimizeXor(int num1, int num2) {
        if(sett(num1)==sett(num2))
        {
            return num1;
        }
        if(sett(num1)>sett(num2))
        {
            int n=sett(num1)-sett(num2);
            for(int i=0;i<32;i++)
                {   if(n==0)
                   {  
                      break;
                   }
                    if((num1&(1<<i))!=0)
                    {   
                        num1=num1&(~(1<<i));
                        n--;
                    }
                }
                return num1;
        }
        else
        {   int n=sett(num2)-sett(num1);
            for(int i=0;i<32;i++)
                {   if(n==0)
                   {  
                      break;
                   }
                    if((num1&(1<<i))==0)
                    {   
                        num1=num1|(1<<i);
                        n--;
                    }
                }
                return num1;
        }
        
    }
};