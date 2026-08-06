class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int evencount = 0;
        for( int i : nums ){

            int digit = to_string(i).length();
            
            if( digit % 2 == 0 ){
                evencount++;
            }
        }
        return evencount;
    }
};