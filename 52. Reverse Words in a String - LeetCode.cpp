class Solution {
public:
    string reverseWords(string s) {
        int i = s.length() - 1;
        string ans = "";

        while(i >= 0){

            while(i >= 0 && s[i] == ' '){
                i--;
            }

            if(i >= 0 && s[i] != ' ' && ans.length() != 0){
                ans += ' ';
            }
            
            string word = "";
            while(i >= 0 && s[i] != ' '){
                word += s[i];
                i--;
            }

            reverse(word.begin(), word.end());
            ans += word;
        }

        return ans;
    }
};
