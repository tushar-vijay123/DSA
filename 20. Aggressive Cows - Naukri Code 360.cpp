bool isPossible(vector<int> stalls, int n, int k, int minAllowedDist) {
    sort(stalls.begin(), stalls.end());

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
    int maxi = stalls[0], mini = stalls[0];
    int n = stalls.size();
    for(int i = 0; i < n; i++) {
        if(stalls[i] > maxi)
            maxi = stalls[i];
        if(stalls[i] < mini)
            mini = stalls[i];
    }

    int s = 1, e = maxi - mini; // minimum & maximum distance -> range
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
