class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        
        int right = -1;
        for( int i = n - 1 ; i>=0 ; i-- ){
            if( ( num[i]-'0')%2 != 0 ){
                right = i;
                break;
            }
        }
        
        if( right == -1 ){
            return "";
        }
        
        int left = 0;
        while( left < right && num[left] == '0'){
            left++;
        }
        
        return num.substr( left , right - left +1 );
    }
};