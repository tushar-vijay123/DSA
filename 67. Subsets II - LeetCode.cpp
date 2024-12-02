class Solution {
public:
    void subsets(vector<int> &nums, vector<int> &curr_sub, int i, vector<vector<int>> &allSubsets){
        if(i == nums.size()){
            allSubsets.push_back(curr_sub);
            return;
        }

        // inclusion
        curr_sub.push_back(nums[i]);
        subsets(nums, curr_sub, i + 1, allSubsets);

        // exclusion
        curr_sub.pop_back();

        int idx = i + 1;
        while(idx < nums.size() && nums[idx] == nums[idx - 1]){
            idx++;
        }

        subsets(nums, curr_sub, idx, allSubsets);        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        vector<vector<int>> allSubsets;
        vector<int> curr_sub;

        subsets(nums, curr_sub, 0, allSubsets);

        return allSubsets;
    }
};
