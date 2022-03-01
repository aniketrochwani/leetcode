class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        // starting from left to right 
        // check if string is valid or not
        // if not valid replace * with string
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') {
                cnt--;
                if(cnt < 0) {
                    s[i] = '*';
                    cnt = 0;
                }
            }
        }
        
        cnt =  0;
        // starting from right to left
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == ')') cnt++;
            else if(s[i] == '(') {
                cnt--;
                if(cnt < 0) {
                    s[i] = '*';
                    cnt = 0;
                }
            }
        }
        string ans = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] != '*') ans += s[i];
        }
        return ans;
    }
};