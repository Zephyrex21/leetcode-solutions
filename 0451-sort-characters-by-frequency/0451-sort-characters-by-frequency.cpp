class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;
        for( char c : s ){
            freq[c]++;
        }

        vector<pair<char,int>> v;
        for( auto &p : freq ){
            v.push_back( { p.first, p.second } );
        }

        sort( v.begin() , v.end() , []( auto &a, auto &b ){
            if( a.second != b.second ){
                return a.second > b.second ;
            }
            return a.first < b.first ;
        });

        string ans;
        for (auto &p : v) {
            for (int i = 0; i < p.second; i++) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};