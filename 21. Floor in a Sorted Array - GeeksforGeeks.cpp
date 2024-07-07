class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x) {

        long long ans = -1;
        
        long long s = 0;
        long long e = n - 1;
        
        long long mid = s + (e - s)/2;
        
        while(s <= e)
        {
            if(v[mid] <= x)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            
            mid = s + (e - s)/2;
        }
        
        return ans;
    }
};
