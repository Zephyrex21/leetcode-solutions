class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;

        vector<int> temp(k);

        // Store last k elements
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Shift remaining elements to the right
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }

        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};