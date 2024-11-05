class Solution {
public:
    bool binarySearch(vector<int> row, int target){
        int s = 0;
        int e = row.size() - 1;

        while(s <= e){

            int mid = s + (e - s)/2;

            if(row[mid] == target){
                return true;
            }else if(row[mid] > target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // binary search on matrix for rows
        int sRow = 0;
        int eRow = m - 1;
        
        while(sRow <= eRow){

            int midR = sRow + (eRow - sRow)/2;

            if(target >= matrix[midR][0] && target <= matrix[midR][n - 1]){
                // binary search in row
                return binarySearch(matrix[midR], target);
            }else if(target > matrix[midR][n - 1]){
                sRow = midR + 1;
            }else{
                eRow = midR - 1;
            }
        }

        return false;
    }
};
