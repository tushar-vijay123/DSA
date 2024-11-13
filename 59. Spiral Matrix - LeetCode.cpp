class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int sRow = 0, sCol = 0;
        int eRow = m - 1, eCol = n - 1;

        vector<int> ans;

        while(sRow <= eRow && sCol <= eCol){
            // top
            for(int i = sCol; i <= eCol; i++){
                ans.push_back(mat[sRow][i]);
            }

            // right
            for(int i = sRow+1; i <= eRow; i++){
                ans.push_back(mat[i][eCol]);
            }

            // bottom
            for(int i = eCol-1; i >= sCol; i--){
                if(sRow == eRow)
                    break;
                ans.push_back(mat[eRow][i]);
            }

            // left
            for(int i = eRow-1; i >= sRow+1; i--){
                if(sCol == eCol)
                    break;
                ans.push_back(mat[i][sCol]);
            }
            sRow++; sCol++; eRow--; eCol--;
        }

        return ans;
    }
};
