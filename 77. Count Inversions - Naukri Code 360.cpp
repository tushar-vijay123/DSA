// MERGE SORT
// #include <bits/stdc++.h> 
// long long merge(vector<int> &arr, long long st, long long mid, long long end){
//     vector<long long> temp;
//     long long i = st;
//     long long j = mid + 1;
//     long long invCount = 0;

//     while(i <= mid && j <= end){
//         if(arr[i] <= arr[j]){
//             temp.push_back(arr[i]);
//             i++;
//         }else{
//             temp.push_back(arr[j]);
//             j++;
//             invCount += (mid - i + 1);
//         }
//     }

//     while(i <= mid){
//         temp.push_back(arr[i]);
//         i++;
//     }

//     while(j <= end){
//         temp.push_back(arr[j]);
//         j++;
//     }

//     for(long long idx = 0; idx < temp.size(); idx++){
//         arr[idx + st] = temp[idx];
//     }

//     return invCount;
// }   

// long long mergeSort(vector<int> &arr, long long st, long long end){
//     if(st < end){
//         long long mid = st + (end - st)/2;

//         long long leftInvCount = mergeSort(arr, st, mid);
//         long long rightInvCount = mergeSort(arr, mid + 1, end);

//         long long invCount = merge(arr, st, mid, end);

//         return leftInvCount + rightInvCount + invCount;
//     }

//     return 0;
// }

// long long getInversions(long long *arr, int n){

//     int st = 0;
//     int e = n - 1;

//     long long ans = mergeSort(arr, st, e);

//     return ans;
// }

// NESTED LOOPS
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    int count = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            	if(arr[i] > arr[j]) count++;
        }
    }

    return count;
}
