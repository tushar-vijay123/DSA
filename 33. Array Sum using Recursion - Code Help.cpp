#include <iostream>
using namespace std;

int getSum(int *arr, int size)
{
  if(size == 0)
  {
    return 0;
  }
  
  int sum = arr[0] + getSum(arr + 1, size - 1);
  
  return sum;
}

int main() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    
    cout<<"Sum of the array is: "<<getSum(arr, size)<<endl;
    
    return 0;
}
