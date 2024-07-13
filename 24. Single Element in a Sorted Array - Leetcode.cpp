class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Approach - using even and odd length (index) to determine whether a subarray contains unique element or not
        int left = 0, right = nums.size() - 1;
        int mid = left + (right - left)/2;

        while(left < right)
        {
            if(mid % 2 == 1)
            {
                mid--;
            }
            if(nums[mid] == nums[mid + 1])
            {
                left = mid + 2;
            }
            else
            {
                right = mid - 1;
            }
            mid = left + (right - left)/2;
        }
        return nums[left];
    }
};
