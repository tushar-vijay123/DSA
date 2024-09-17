class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's Voting Algorithm
        int freq = 0, ans = 0;

        for(int el: nums)
        {
            if(freq == 0)
                ans = el;
            
            if(ans == el)
                freq++;
            else
                freq--;
        }

        int frequency = 0;
        for(int el: nums)
        {
            if(el == ans)
                frequency++;
        }

        if(frequency > nums.size()/2)
            return ans;
        else
            return -1;
    }
};
