class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long long largest = LONG_MIN;
        long long slargest = LONG_MIN;
        long long tlargest = LONG_MIN;

        for( int  x : nums ){

            if( x == largest || x == slargest || x == tlargest ){
                continue;
            }

            if( x > largest ){
                tlargest = slargest ;
                slargest = largest;
                largest = x;
            }

            else if( x > slargest ){
                tlargest = slargest;
                slargest = x;
            }

            else if( x > tlargest ){
                tlargest = x;
            }
        }

        if( tlargest == LONG_MIN ){
            return largest;
        }

        return tlargest;

    }
};