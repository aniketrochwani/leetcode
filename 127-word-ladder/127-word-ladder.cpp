class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> store(wordList.begin(), wordList.end());
        
        queue<string> qu; 
        qu.push(beginWord);
        
        int ans = 1;
        while(!qu.empty()){
            int size = qu.size();
            for(int i=0; i<size; i++){
                string word = qu.front();
                qu.pop();
                
                if(word == endWord) return ans;
                
                store.erase(word);
                
                for(int j=0; j<word.size(); j++){
                    char ch = word[j];   
                    for(int k=0; k<26; k++){
                        word[j] = 'a'+k;
                        if(store.find(word) != store.end()){
                            qu.push(word);
                        }
                    }
                    word[j] = ch;
                }
            }
            ans++;
        }
        
        return 0;
    }
};