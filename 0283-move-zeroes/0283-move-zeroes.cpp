class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        // j = position where next non-zero should go
        int j = 0;

        // Place all non-zero elements at the front
        for (int i = 0; i < n; i++) {

            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        // Fill remaining positions with zeroes
        while (j < n) {
            nums[j] = 0;
            j++;
        }
    }
};