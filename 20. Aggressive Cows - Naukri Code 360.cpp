bool isPossible(vector<int> stalls, int n, int k, int minAllowedDist) {
    
    int cows = 1;
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPos >= minAllowedDist) {
            cows++;
            lastPos = stalls[i];
        }
        if(cows == k)
            return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();

    int s = 1, e = stalls[n-1] - stalls[0]; // minimum & maximum distance -> range
    int ans = -1;

    while(s <= e) {
        int mid = s + (e - s)/2;

        if(isPossible(stalls, n, k, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return ans;
}
