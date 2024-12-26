class Solution {
public:
    int partition(vector<int> &nums, int st, int end){
        int idx = st - 1;
        int pivot = nums[end];
        for(int j = st; j < end; j++){ // putting smaller elements on left
            if(nums[j] < pivot){
                idx++;
                swap(nums[j], nums[idx]);
            }
        }

        idx++;
        swap(nums[end], nums[idx]);
        
        return idx;
    }

    void quickSort(vector<int> &nums, int st, int end){
        if(st < end){
            int pivIdx = partition(nums, st, end);
            quickSort(nums, st, pivIdx - 1); // left
            quickSort(nums, pivIdx + 1, end); // right
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }
};
