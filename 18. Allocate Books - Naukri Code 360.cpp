bool isPossible(vector<int>& arr, int n, int m, int mid)
{
    int studCount = 1;
    int pageSum = 0;
    
    for(int i=0; i<n; i++){
        if(pageSum+arr[i]<=mid){
            pageSum += arr[i];
        }
        else{
            studCount++;
            if(studCount>m || arr[i]>mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
    {
        return -1;
    }
    int s = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int e = sum;
    int mid = s+(e-s)/2;
    int ans = -1;
    
    while(s<=e){
        if(isPossible(arr, n, m, mid)){
            e = mid-1;
            ans = mid;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
