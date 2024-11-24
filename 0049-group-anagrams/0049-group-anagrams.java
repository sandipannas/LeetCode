class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
 Map<String , List<String>> mmm=new HashMap<>();
 for(String sss:strs)
 {
    char[] aaa=sss.toCharArray();
    Arrays.sort(aaa);
    String new_str=String.valueOf(aaa);
    if(!(mmm.containsKey(new_str)))
    {
        mmm.put(new_str,new ArrayList<>());
    }
    mmm.get(new_str).add(sss);
 }
   return new ArrayList<>(mmm.values()); }
}
