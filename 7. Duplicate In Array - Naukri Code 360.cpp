int findDuplicate(vector<int> &arr) 
{
    int ans = 0;
    int size = arr.size();

    for(int i=0; i<size; i++)
    {
        ans ^= arr[i];
    }

    for(int j=1; j<=size-1; j++)
    {
        ans ^= j;
    }

    return ans;
	
}
