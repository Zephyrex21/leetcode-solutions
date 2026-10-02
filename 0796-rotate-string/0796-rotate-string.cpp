class Solution {
public:
    bool rotateString(string s, string goal) {
        if( s.length() != goal.length() ){
            return false;
        }

        string doubled = s+s;

        bool ans = doubled.find(goal) != string::npos;

        return ans;
    }
};