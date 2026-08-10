class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // size of invervals arry
        int n = intervals.size();

        // sorting the intervls
        sort( intervals.begin() , intervals.end() );

        // a vector to store the merget interva;s
        vector< vector<int> > ans;

        // add first interval into the vector
        ans.push_back( intervals[0] );

        // traversing the remaining intervals
        for( int i = 1 ; i < n ; i++ ){

            // Overlap
            if( ans.back()[1] >= intervals[i][0] ){

                //merge
                ans.back()[1] = max( ans.back()[1] , intervals[i][1] );
            }
            // no overlap
            else{

                ans.push_back( intervals[i] );
            }
        }
        return ans;
    }
};