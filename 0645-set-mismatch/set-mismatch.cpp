class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();

        vector<int> freq( n + 1 , 0 );

        for( int num : nums ){
            freq[num]++;
        }

        int duplicate = -1;
        int missing  = -1;

        for( int i = 1 ; i <= n ; i++ ){
            
            if( freq[i] == 2 ) duplicate = i;

            if( freq[i] == 0 ) missing = i;

        }

        return { duplicate , missing };
    }
};