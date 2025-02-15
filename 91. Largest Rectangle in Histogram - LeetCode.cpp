class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightSmallerIdx (n, 0);
        vector<int> leftSmallerIdx (n, 0);
        stack<int> s;

        // right smaller
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            rightSmallerIdx[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        // left smaller
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            leftSmallerIdx[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        // calculating area
        int area = 0;

        for(int i = 0; i < n; i++){
            int width = rightSmallerIdx[i] - leftSmallerIdx[i] - 1;
            int currArea = heights[i] * width;
            area = max(area, currArea);
        }

        return area;
    }
};
