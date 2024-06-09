#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int el)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == el)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int key;
    cout<<"Enter element to search: ";
    cin>>key;

    bool ans = linearSearch(arr, 5, key);

    if(ans)
    {
        cout<<"Element is present."<<endl;
    }
    else
    {
        cout<<"Element is not present."<<endl;
    }

    return 0;
}
