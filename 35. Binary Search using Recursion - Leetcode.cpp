class Solution {
public:
    int binarySearch(vector<int> &arr, int s, int e, int target){
        // base case
        if(s > e)
            return -1;
        
        int mid = s + (e - s)/2;
        if(arr[mid] == target)
            return mid;

        if(arr[mid] < target)
        {
        return binarySearch(arr, mid + 1, e, target);
        }
        else
        {
        return binarySearch(arr, s, mid - 1, target);
        }
    }
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;

        return binarySearch(nums, s, e, target);
    }
};
