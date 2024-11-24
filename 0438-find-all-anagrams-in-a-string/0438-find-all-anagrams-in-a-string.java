class Solution {
    public List<Integer> findAnagrams(String s, String p) {
      HashMap<Character,Integer> gg=new HashMap<>();  
      HashMap<Character,Integer> og=new HashMap<>();
      List<Integer> ff=new ArrayList<>();

      if(p.length()>s.length())
      {
        return ff;
      }


      for(int i=97;i<=122;i++)
      {
        gg.put((char)(i),0);
        og.put((char)(i),0);
      }


      for(int i=0;i<p.length();i++)
      {
        gg.put(p.charAt(i),gg.get(p.charAt(i))+1);
        og.put(s.charAt(i),og.get(s.charAt(i))+1);
      }
      if(gg.equals(og))
        {
            ff.add(0);
            
        }
    //og.put(s.charAt(0),og.get(s.charAt(0))-1);
    int l=0;
    int r=l+(p.length()-1);
    


      
      while(r<s.length()-1)
      { og.put(s.charAt(l),og.get(s.charAt(l))-1);
            l++;
            r++;
        og.put(s.charAt(r),og.get(s.charAt(r))+1);
        if(gg.equals(og))
        {
            ff.add(l);
            
        }
    
            
        }

    return ff;}
}