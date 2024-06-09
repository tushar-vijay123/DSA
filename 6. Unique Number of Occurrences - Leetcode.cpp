class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        int size = arr.size();

        // mapping elements with their count
        for(int i=0; i<size; i++)
        {
            mp[arr[i]]++;
        }

        vector<int> count;
      
        // storing counts in an array
        for(auto it: mp)
        {
            count.push_back(it.second);
        }

        sort(count.begin(), count.end());

        // comparing the counts
        for(int i=0; i<count.size()-1; i++)
        {
            if(count[i] == count[i+1])
            {
                return false;
            }
        }

        return true;
    }
};
