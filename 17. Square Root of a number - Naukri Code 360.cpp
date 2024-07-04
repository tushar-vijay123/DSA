int floorSqrt(int n)
{
    if(n == 0 || n == 1)
        return n;

  // USING BINARY SEARCH FOR O(logN) COMPLEXITY
    int s = 1, e = n;
    long long int ans = 1;

    while(s <= e)
    {
        long long mid = s + (e - s)/2;
        long long square = mid * mid;

        if(square == n)
        {
            return mid;
        }
        else if(square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }   
    }

    return ans;
}
