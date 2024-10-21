class Solution {
public:
    bool isPalindrome(string s) {

        if(s.length() == 0 || s.length() == 1){
            return true;
        }

        string new_s = "";

        // converting to lowercase using reference
        for(auto &i: s){
            i = tolower(i);
        }

        // removing non-alphanumeric
        for(auto i: s){
            if((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9')){
                new_s += i;
            }
        }

        int i = 0, j = new_s.length()-1;
        while(i < j){
            if(new_s[i++] != new_s[j--]){
                return false;
            }
        }

        return true;
    }
};
