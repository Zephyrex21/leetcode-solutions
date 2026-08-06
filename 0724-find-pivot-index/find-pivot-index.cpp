class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total = 0;
        for ( int num : nums ){
            total = total + num ;
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