int lower_bound(vector<int> &a, int n, int x)
{
	int s = 0, e = n - 1;
	int mid = s + (e - s)/2;
	int ans = -1;

	while(s <= e)
	{
		if(a[mid] <= x)
		{
			ans = mid;
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}

		mid = s + (e - s)/2;
	}

	return ans;
}

int upper_bound(vector<int> &a, int n, int x)
{
	int s = 0, e = n - 1;
	int mid = s + (e - s)/2;
	int ans = -1;

	while(s <= e)
	{
		if(a[mid] >= x)
		{	
			ans = mid;
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}

		mid = s + (e - s)/2;
	}

	return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {

	int lower = lower_bound(a, n, x);
	int upper = upper_bound(a, n, x);

	int lower_ans = -1;
	int upper_ans = -1;

	if(lower > -1)
	{
		lower_ans = a[lower];
	}

	if(upper > -1)
	{
		upper_ans = a[upper];
	}

	return {lower_ans, upper_ans};
}
