class Solution {
public:
    int trap(vector<int>& height) {
        // //PREFIX ARRAY APPROACH
        // int n = height.size();
        // vector<int> lmax(n, 0);
        // vector<int> rmax(n, 0);

        // lmax[0] = height[0];
        // rmax[n - 1] = height[n - 1];

        // //calculating left max array
        // for(int i = 1; i < n; i++){
        //     lmax[i] = max(lmax[i - 1], height[i]);
        // }

        // //calculating right max array
        // for(int i = n - 2; i >= 0; i--){
        //     rmax[i] = max(rmax[i + 1], height[i]);
        // }

        // //calculating water
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     ans += (min(lmax[i], rmax[i]) - height[i]);
        // }

        // return ans;

        // TWO-POINTER APPROACH
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int lmax = height[0];
        int rmax = height[n - 1];

        int ans = 0;

        while(l < r){
            if(lmax < rmax){
                ans += (lmax - height[l]);
                l++;
                lmax = max(lmax, height[l]);
            }else{
                ans += (rmax - height[r]);
                r--;
                rmax = max(rmax, height[r]);
            }
        }

        return ans;
    }
};
