class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(nums.size());

        for(int i = 2*n - 1; i >= 0; i--){
            // popping index of smaller elements from stack
            while(!s.empty() && nums[s.top()] <= nums[i % n]){
                s.pop();
            }

            // assigning values in answer array
            ans[i % n] = (s.size() == 0 ? -1 : nums[s.top()]);

            // pushing current element's index in stack
            s.push(i % n);
        }

        return ans;
    }
};
