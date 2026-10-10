class Solution {
private:
    int countParts(vector<int>& nums, int limit) {
        int parts = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > limit) {
                parts++;
                sum = nums[i];
            }
            else {
                sum += nums[i];
            }
        }

        return parts;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            int parts = countParts(nums, mid);

            if (parts > k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }
};