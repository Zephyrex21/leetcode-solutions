class Solution {
public:

    bool containsDuplicate(vector<int>& nums) {

        sort( nums.begin() , nums.end() );       // sort the array     

        for( int i = 1 ; i < nums.size() ; i++ ){

            if( nums[i] == nums[i-1] ){             // check adjacent elements -> if equal -> duplicate 
                return true;
            }
        }
        return false;
    }
};