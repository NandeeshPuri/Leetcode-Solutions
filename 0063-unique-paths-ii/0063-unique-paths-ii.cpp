class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();
        if(o[0][0] == 1 || o[m - 1][n - 1] == 1) return 0;
        o[0][0] = 1;
        for(int i = 1; i < n; i++){
            o[0][i] = (o[0][i] == 1 ? 0 : (o[0][i - 1] == 0 ? 0 : 1));
        }
        for(int i = 1; i < m; i++){
            o[i][0] = (o[i][0] == 1 ? 0 : (o[i - 1][0] == 0 ? 0 : 1));
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                o[i][j] = o[i][j] == 1 ? 0 : o[i - 1][j] + o[i][j - 1];
            }
        }
        return o[m - 1][n - 1];
            
        
    }
};