class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();

        for( int  i = n - 1 ; i >=0 ; i-- ){

            if( digits[i] < 9 ){     // if digit is < 9 -> simply add 1 
                digits[i]++;
                return digits;
            }

            digits[i] = 0;    // if digit is == 9 ; make it 0  -> carry = 1
        }

        // if all digits were 9 
        digits.insert(  digits.begin() , 1 );       // one carry left -> insert it at start

        return digits;
    }
};