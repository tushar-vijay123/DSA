class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> s;

        for(int i = nums2.size() - 1; i >= 0; i--){
            while(s.size() > 0 && s.top() <= nums2[i]){
                s.pop();
            }

            if(s.empty()){
                nextGreater[nums2[i]] = -1;
            }else{
                nextGreater[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        vector<int> ans(nums1.size());

        for(int i = 0; i < nums1.size(); i++){
            ans[i] = nextGreater[nums1[i]];
        }

        return ans;
    }
};
