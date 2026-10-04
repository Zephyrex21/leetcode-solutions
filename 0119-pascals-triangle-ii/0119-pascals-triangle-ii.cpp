class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for( int col = 1 ; col < rowIndex ; col++ ){
            ans = ans * ( rowIndex - col+1 );
            ans = ans / (col);
            ansRow.push_back(ans);
        }
        
        if (rowIndex > 0) {
            ansRow.push_back(1);
        }

        return ansRow;

    }
};