class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> words;
        int i = 0;
        int n = s.length();

        while(i < n)
        {
            // skip spaces
            while(i < n && s[i] == ' ')
                i++;

            string word = "";

            // build word
            while(i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            if(word.length() > 0)
                words.push_back(word);
        }


        // reverse words
        reverse(words.begin(), words.end());

        string ans = "";

        for(int i = 0; i < words.size(); i++)
        {
            ans += words[i];

            if(i != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};