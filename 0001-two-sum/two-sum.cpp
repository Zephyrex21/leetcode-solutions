#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> map;

        for( int i = 0 ; i < nums.size() ; i++ ){

            int needed = target - nums[i];

            if( map.find(needed) != map.end()){
                return { map[needed] , i }; 
            }

            map[ nums[i] ] = i ;
        }
        return {};
    }
};