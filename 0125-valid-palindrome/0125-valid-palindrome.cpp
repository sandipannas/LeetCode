class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;

        while(left<=right){
            while(left<=right && !isalnum(s[left])) left++;
            while(left<=right && !isalnum(s[right])) right--;

            if(left>right){ break;}

            if(s[left]>='0' && s[left]<='9' && s[left]!=s[right]){
                return false;
            }

            if(tolower(s[left])!=tolower(s[right])) return false;

            left++; right--;
        }

        return true;
    }
};