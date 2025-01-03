class Solution {
    public boolean isAnagram(String s, String t) {
       if(s.length()!=t.length()){return false;}

       int n=s.length();
       int alpha[]=new int[26];
       for(int i=0;i<n;i++)
       {
        alpha[(int)(s.charAt(i)-'a')]++;
        alpha[(int)(t.charAt(i)-'a')]--;
       }
        
       for(int i=0;i<26;i++)
       {
        if(alpha[i]!=0)
        {
            return false;
        }
       }
       return true;
    }
}