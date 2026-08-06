class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        string temp;
        int open = 0;

        // Pass 1: remove extra ')'
        for (char ch : s) {
            if (ch == '(') {
                open++;
                temp += ch;
            }
            else if (ch == ')') {
                if (open > 0) {
                    open--;
                    temp += ch;
                }
                // else skip
            }
            else {
                temp += ch; // normal character
            }
        }

        // Pass 2: remove extra '('
        string result;
        for (int i = temp.size() - 1; i >= 0; i--) {
            if (temp[i] == '(' && open > 0) {
                open--;
                continue; // skip extra '('
            }
            result += temp[i];
        }

        reverse(result.begin(), result.end());
        return result;

    }
};