#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int key)
{
  if(size == 0)
  {
    return false;
  }
  
  if(arr[0] == key)
  {
    return true;
  }
  else
  {
    return linearSearch(arr + 1, size - 1, key);
  }
}

int main() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int key = 2;
    
    if(linearSearch(arr, size, key))
    {
      cout<<"Key is present."<<endl;
    }
    else
    {
      cout<<"Key is not present."<<endl;
    }
    
    return 0;
}
