class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();

        // step1 : find the pivot element
        int i = n - 2 ;
        while( i >=0 && nums[i] >= nums[i+1] ){
            i--;
        }

        // step2 : find successor and swap
        if( i >= 0 ){
            int j = n - 1;
            while( nums[j] <= nums[i] ){
                j--;
            }
            swap( nums[j] , nums[i] );
        }

        // step3 : reverse the suffix
        reverse( nums.begin()+i+1 , nums.end() );
    }
};