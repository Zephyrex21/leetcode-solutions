class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxi = nums[0];
        long long mini = nums[0];

        long long ans = nums[0];

        for( int i = 1 ; i < nums.size() ; i++ ){

            long long x = nums[i];

            long long a = x;
            long long b = maxi*x;
            long long c = mini*x;

            maxi = max( {a,b,c} );
            mini = min( {a,b,c} );

            ans = max( ans , maxi );
        }

        return ans;
    }
};