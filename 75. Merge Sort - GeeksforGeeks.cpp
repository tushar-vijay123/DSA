class Solution {
  public:
    void merge(vector<int> &arr, int start, int mid, int end){
        int i = start, j = mid + 1;
        vector<int> temp;
        
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j <= end){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int idx=0; idx < temp.size(); idx++){
            arr[idx+start] =  temp[idx];
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l < r){
            int mid = l + (r - l)/2;
            
            mergeSort(arr, l, mid); // left half
            mergeSort(arr, mid+1, r); // right half
            
            merge(arr, l, mid, r);
        }
    }
};
