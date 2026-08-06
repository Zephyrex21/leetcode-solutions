class Solution {
public:

    // This approach is also known as Dutch national Flag Algorithm

    void sortColors(vector<int>& nums) {
        
        int n  = nums.size();     // size of array

        int low = 0;             // we will use 3 pointers low n mid starting from start index 
        int mid = 0;
        int high = n -1;           // high pointer will start from last index

        while(  mid <= high ){

            if( nums[mid] == 0 ){              // case-1 if mid is 0 -> move it to front 
                swap( nums[low] , nums[mid] );
                low++;
                mid++;
            }

            else if( nums[mid] == 1 ){     // case-2 if mid is 1 -> already at right position.. no swap needed
                mid++; 
            }

            else{                                  // case-3 if mid is 2.. swap mid with high -> place at last 
                swap( nums[mid] , nums[high] );
                high--;
            }
        }
    }
};