class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<int> rows;
        vector<int> columns;
        int n = mat.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 0){
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }
        for(int i = 0; i < rows.size(); i++){
            for(int j = 0; j < mat[0].size(); j++)
                mat[rows[i]][j] = 0;
        }
        for(int i = 0; i < columns.size(); i++){
            for(int j = 0; j < n; j++)
                mat[j][columns[i]] = 0;
        }
    }
};