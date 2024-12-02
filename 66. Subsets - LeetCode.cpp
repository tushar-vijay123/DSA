class Solution {
public:
    void subsets(vector<int> &arr, vector<int> &curr_subset, int index, vector<vector<int>> &ans){
        if(index == arr.size()){
            ans.push_back(curr_subset);
            return;
        }

        // inclusion
        curr_subset.push_back(arr[index]);
        subsets(arr, curr_subset, index + 1, ans);

        curr_subset.pop_back(); // backtrack step for excluding

        // exclusion
        subsets(arr, curr_subset, index + 1, ans);
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> curr_subset;

        subsets(arr, curr_subset, 0, ans);

        return ans;
    }
};
