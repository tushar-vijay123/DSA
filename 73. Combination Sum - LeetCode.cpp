class Solution {
public:
    set<vector<int>> s;
    void combSum(vector<int>& candidates, int i, vector<int> &combination, vector<vector<int>> &ans, int target){
        if(i == candidates.size() || target < 0){
            return;
        }

        if(target == 0){
            if(s.find(combination) == s.end()){
                ans.push_back(combination);
                s.insert(combination);
            }
            return;
        }

        combination.push_back(candidates[i]);
        combSum(candidates, i+1, combination, ans, target-candidates[i]); // single inclusion
        combSum(candidates, i, combination, ans, target-candidates[i]); // multiple inclusion
        combination.pop_back(); // backtacking
        combSum(candidates, i+1, combination, ans, target); // exclusion

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;

        combSum(candidates, 0, combination, ans, target);

        return ans;
    }
};
