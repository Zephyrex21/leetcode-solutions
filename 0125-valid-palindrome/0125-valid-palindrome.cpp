class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.size();
        int left = 0;
        int right = n-1;

        while( left < right ){

            // skip non-alphanumeric characters
            while( left < right && !isalnum(s[left]) ){
                left++;
            }
            while( left < right && !isalnum(s[right]) ){
                right--;
            }

            // comparing after converting to lowercase
            if( tolower(s[left]) != tolower(s[right])){
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};