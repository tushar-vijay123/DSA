class Solution {
  public:
    bool isValid(int arr[], int n, int m, long long maxAllowedPages) {
        int stu = 1;
        long long pages = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(arr[i] > maxAllowedPages) return false;
            
            if(pages + arr[i] <= maxAllowedPages) {
                pages += arr[i];
            } else {
                stu++;
                pages = arr[i];
            }
        }
        
        return stu > m ? false : true;
    }
    
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        
        if(n < m) {
            return -1;
        }
        
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        
        long long s = 0, e = sum, ans = -1;
        
        while(s <= e) {
            long long mid = s + (e - s)/2;
            
            if(isValid(arr, n, m, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        return ans;
    }
};
