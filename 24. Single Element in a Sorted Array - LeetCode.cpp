class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        if(arr.size() == 1)
        {
            return arr[0];
        }

        int s = 0, e = arr.size() - 1;

        while(s <= e)
        {
            int mid = s + (e - s)/2;
            
            if(mid < arr.size() - 1 && arr[mid] == arr[mid + 1])
            {
                if(mid % 2 != 0)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else if(mid > 0 && arr[mid] == arr[mid - 1])
            {
                if(mid % 2 == 0)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else
            {
                return arr[mid];
            }
        }

        return -1;
    }
};
