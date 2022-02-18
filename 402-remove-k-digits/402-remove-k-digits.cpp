class Solution {
public:
    string removeKdigits(string num, int k) {
        string finl = "";
        finl.push_back(num[0]);
        
        for(int i=1; i<num.size(); i++){
            while(finl.back()>num[i] and k){
                k--;
                finl.pop_back();
            }
            
            if(finl.size() or num[i] != '0') finl.push_back(num[i]); //dont include leading zeroes
        }
        
        while(finl.size() and k){
            finl.pop_back();
            k--;
        }
        
        if(finl == "") return "0";
            
        return finl;
    }
};