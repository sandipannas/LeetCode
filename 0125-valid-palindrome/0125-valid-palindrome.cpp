class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        //turn the s to lowercase

        while(left<right){
            while(left<right && !( (int)s[left]>=48 && (int)s[left]<=57 ||
                            (int)s[left]>=65 && (int)s[left]<=90 ||
                            (int)s[left]>=97 && (int)s[left]<=122 )) {
                                //cout<<"skipping "<<s[left]<<endl;
                                left++;
            } 
            while(right>left && !( (int)s[right]>=48 && (int)s[right]<=57 ||
                            (int)s[right]>=65 && (int)s[right]<=90 ||
                            (int)s[right]>=97 && (int)s[right]<=122)){
                                //cout<<"skipping "<<s[right]<<endl;
                                right--;
            }
            
           // cout<<"compa "<<s[left]<<" with "<<s[right]<<endl;
            if(tolower(s[left])!=tolower(s[right])){ return false;}
            left++;
            right--;
        }

        return true;
    }
};