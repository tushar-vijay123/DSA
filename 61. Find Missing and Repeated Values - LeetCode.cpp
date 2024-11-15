class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans;
        unordered_set<int> st;
        int actual_sum = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int el = grid[i][j];
                if(st.find(el) != st.end()){
                    ans.push_back(el);
                }else{
                    st.insert(el);
                }
                actual_sum += el;
            }
        }

        // finding missing value
        int exp_sum = ((n*n) * ((n*n) + 1))/2;
        ans.push_back(exp_sum - (actual_sum - ans[0]));

        return ans;
    }
};
