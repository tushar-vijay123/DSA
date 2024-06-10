class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // O(n) time complexity
        vector<int> ans;
        int len = nums.size();

        for(int i=0; i<len; i++)
        {
            int el = nums[abs(nums[i]) - 1];
            if(el < 0)
            {
                ans.push_back(abs(nums[i]));
            }
            else
            {
                nums[abs(nums[i]) - 1] *= (-1);
            }
        }

        return ans;
    }
};
