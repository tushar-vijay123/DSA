#include <bits/stdc++.h> 
int pairSum(vector<int> &arr, int n, int target){
	int s = 0, e = n-1;
	int count = 0;
  // two pointer approach
	while(s < e)
	{
		if(arr[s] + arr[e] == target)
		{
			count++;
			s++;
			e--;
			while(s < e && arr[s-1] == arr[s])
				s++;
			while(s < e && arr[e+1] == arr[e])
				e--;
		}
		else if(arr[s] + arr[e] > target)
		{
			e--;
		}
		else
		{
			s++;
		}
	}

	if(count > 0)
	{
		return count;
	}
	else
	{
		return -1;
	}
}
