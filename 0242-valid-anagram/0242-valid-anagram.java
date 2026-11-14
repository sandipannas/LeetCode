class Solution {
    public boolean isAnagram(String s, String t) {
        int[] map=new int[26];

        if(s.length()!=t.length()) return false;

        for(int i=0;i<s.length();i++){
            map[s.charAt(i)-'a']++;
        }
        for(int i=0;i<t.length();i++){
            if(map[t.charAt(i)-'a']==0) return false;
            map[t.charAt(i)-'a']--;
        }

        return true;
    }
}