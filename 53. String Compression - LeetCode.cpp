class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";

        for(int i = 0; i < chars.size(); i++){
            int count = 1;
            char temp = chars[i];
            while(i + 1 < chars.size() && chars[i + 1] == temp){
                count++;
                i++;
            }
            ans += temp;
            if(count != 1){
                ans += to_string(count);
            }
        }

        for(int i = 0; i < ans.length(); i++){
            chars[i] = ans[i];
        }

        return ans.length();
    }
};
