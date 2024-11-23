class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Prefix Sum approach
        int n = nums.size();
        int count = 0;
        vector<int> prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        unordered_map<int, int> m; //prefixSum, freq
        for(int j = 0; j < n; j++){
            // case1
            if(prefixSum[j] == k){
                count++;
            }

          // case2
            int val = prefixSum[j] - k;
            if(m.find(val) != m.end()){
                count += m[val];
            }

            // updating map with prefixSum
            if(m.find(prefixSum[j]) == m.end()){
                m[prefixSum[j]] = 0;
            }
            m[prefixSum[j]]++;
        }

        return count;
    }
};
