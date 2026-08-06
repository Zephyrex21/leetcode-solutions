class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<int> zeros(n);

        // Count trailing zeros in each row
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            zeros[i] = count;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int need = n - i - 1;
            int j = i;

            while (j < n && zeros[j] < need)
                j++;

            if (j == n)
                return -1;

            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }

    int main() {
        vector<vector<int>> grid = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};

        cout << minSwaps(grid) << endl;

        return 0;
    }
};