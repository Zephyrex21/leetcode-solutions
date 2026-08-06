class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // n = n0 of rows = no of cols
        int n = matrix.size();

        //Step-1 To transpose the matrix
        for ( int i = 0 ; i < n ; i++){
            for ( int j = i ; j < n ; j++){
                swap( matrix[i][j] , matrix[j][i] );
            }
        }

        //Step-2 Reverse the rows of transposed matrix
        for ( int i=0 ; i < n ; i++ ){
            reverse( matrix[i].begin() , matrix[i].end()  );
        }

    }
};