class Solution {
private:
    void reverseString(vector<char>& s, int left, int right) {

        // Base case
        if (left >= right) {
            return;
        }

        // Swap the two ends
        swap(s[left], s[right]);

        // Reverse the remaining middle part
        reverseString(s, left + 1, right - 1);
    }
public:
    void reverseString(vector<char>& s) {
        reverseString(s, 0, s.size() - 1);
    }
};