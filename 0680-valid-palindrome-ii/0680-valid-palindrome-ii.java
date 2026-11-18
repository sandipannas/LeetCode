class Solution {
    public boolean isIt(String s,int left,int right,int flag){
        while(left<right){
            if(s.charAt(left)!=s.charAt(right)){
                if(flag==1) return false;
                flag=1;
                return isIt(s,left+1,right,1) || isIt(s,left,right-1,1); 
            }

            left++; right--;
        }
        return true;
    }
    public boolean validPalindrome(String s) {
        return isIt(s,0,s.length()-1,0);
    }
}