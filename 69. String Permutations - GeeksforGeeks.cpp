class Solution{
    public:
    void allPermutations(string S, int idx, vector<string> &ans){
        if(idx == S.length()){
            ans.push_back(S);
            return;
        }
        
        for(int i = idx; i < S.length(); i++){
            swap(S[i], S[idx]);
            allPermutations(S, idx + 1, ans);
            
            swap(S[i], S[idx]); // backtracking step
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string> ans;
        
        allPermutations(S, 0, ans);
        
        sort(ans.begin(), ans.end()); // sorting for lexicographical order
        
        // return sort(ans.begin(), ans.end()); => gives error as sort is void function type
        return ans;
    }
};
