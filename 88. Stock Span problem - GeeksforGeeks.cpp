class Solution {
  public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> ans;
        stack<int> s;
        
        for(int i = 0; i < arr.size(); i++){
            
            while(s.size() > 0 && arr[s.top()] <= arr[i]){
                s.pop();
            }
            
            if(s.empty()){
                ans.push_back(i+1);
            }else{
                ans.push_back(i - s.top());
            }
            
            s.push(i);
        }
        
        return ans;
    }
};
