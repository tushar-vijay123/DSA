int firstOccurence(vector<int>& arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid;

    while(s <= e)
    {
        mid = s + (e - s)/2;

        if(arr[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return ans;
}

int lastOccurence(vector<int>& arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid;

    while(s <= e)
    {
        mid = s + (e - s)/2;

        if(arr[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> ans;

    ans.first = firstOccurence(arr, n, k);
    ans.second = lastOccurence(arr, n, k);

    return ans;
}
