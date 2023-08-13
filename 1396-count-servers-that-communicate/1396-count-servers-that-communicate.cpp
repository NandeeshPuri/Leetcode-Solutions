class Solution {
public:

    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int val = 0;
                if(grid[i][j]){
                for(int k = 0; k < n; k++) {
                    if(grid[k][j] && k != i) {
                        val = 1; break;
                    }
                }

                if(!val) {
                    for(int k = 0; k < m; k++) {
                        if(grid[i][k] && k != j) {
                            val = 1; break;
                        }
                    }
                }}

                cout << val << " ";

                ans += val;
            }
            cout << endl;
        }

        return ans;
    }
};