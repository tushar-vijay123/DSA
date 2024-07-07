pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    
    int floor = -1;
    int mini = -1;
    
    int ceil = -1;
    int maxi = 99999999999;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] <= x && arr[i] > mini)
        {
            floor = arr[i];
            mini = arr[i];
        }
        
        if(arr[i] >= x && arr[i] < maxi)
        {
            ceil = arr[i];
            maxi = arr[i];
        }
    }
    
    return {floor, ceil};
}
