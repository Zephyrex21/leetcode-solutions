class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> primitives;
        int n = s.size();

        int depth = 0;
        int start = 0;

        for( int i = 0 ;  i< n ; i++ ){
            if( s[i] == '(' ){
                if( depth == 0 ){
                    start = i;
                }
                depth++;
            }
            else{
                depth--;
                if( depth == 0 ){
                    primitives.push_back(
                        s.substr( start , i - start + 1)
                    );
                }
            }
        }

        string ans = "";
        for( string p : primitives ){
            ans += p.substr( 1 , p.size()-2 );
        }

        return ans;

    }
};