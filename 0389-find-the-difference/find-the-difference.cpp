class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char ans = 0;

        for( char c : s ){
            ans = ans ^ c;
        }

        for( char c : t ){
            ans = ans ^ c;
        }

        return ans;
    }
};