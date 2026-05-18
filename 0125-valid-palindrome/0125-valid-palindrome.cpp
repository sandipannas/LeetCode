class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        //turn the s to lowercase

        while(left<right){
            while(left<right && !isalnum(s[left])) {
                                //cout<<"skipping "<<s[left]<<endl;
                                left++;
            } 
            while(right>left && !isalnum(s[right])){
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