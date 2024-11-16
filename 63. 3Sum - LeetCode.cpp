class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // // **better approach using hashing**
        // int n = nums.size();
        // set<vector<int>> uniqueTriplets;

        // for(int i = 0; i < n; i++){
        //     int tar = -nums[i];
        //     set<int> s;

        //     for(int j = i + 1; j < n; j++){
        //         int third = tar - nums[j];

        //         if(s.find(third) != s.end()){
        //             vector<int> trip = {nums[i], nums[j], third};
        //             sort(trip.begin(), trip.end());
        //             uniqueTriplets.insert(trip);
        //         }

        //         s.insert(nums[j]);
        //     }
        // }

        // vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
        // return ans;

        // ** optimized approach - two pointer **
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){

            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                }
                else if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        return ans;
    }
};
