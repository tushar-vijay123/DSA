class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // finding pivot
        int pivot = -1;
        int n = nums.size();
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // swapping pivot with it's next larger element
        for(int i = n - 1; i > pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // reverse elements (piv + 1 to n - 1)
        reverse(nums.begin() + pivot + 1, nums.end());

    }
};
