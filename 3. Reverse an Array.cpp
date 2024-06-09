#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(int);

    printArray(arr, size);

    //Reversing array
    int s = 0, e = size-1;

    while(s <= e)
    {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;

        s++;
        e--;
    }

    printArray(arr, size);


    return 0;
}
