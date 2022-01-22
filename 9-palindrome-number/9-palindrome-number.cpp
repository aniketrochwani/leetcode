class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<10) return true;
        long long int ans=0,b,qus=x;
            
        while(x){
            b = x%10;
            ans = b+ans*10;
            x = x/10;
        }
        if(ans == qus) return true;
        return false;
    }
};