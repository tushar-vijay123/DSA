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
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr)/sizeof(int);

    for(int i=0; i<size; i+=2)
    {
        if(i+1 < size)
        {
            swap(arr[i], arr[i+1]);
        }
    }

    printArray(arr, size);

    return 0;
}
