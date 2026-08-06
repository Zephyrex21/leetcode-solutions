class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total = 0;
        for ( int num =0; num < nums.size() ; num ++ ){
            total = total + nums[num] ;
        }

        int leftsum = 0;
        for(int i = 0; i < nums.size(); i++) {
            
            if(leftsum == total - leftsum - nums[i]) {
                return i;
            }

            leftsum += nums[i];
        }
        return -1;
    }
};