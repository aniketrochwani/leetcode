class Solution {
public:
    bool checkRow(vector<vector<char>> board){
        for(int i=0; i<9; i++){
            map<char,int> mp;
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    mp[board[i][j]]++;
                }
            }
            for(auto it: mp){
                if(it.second >1){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkCol(vector<vector<char>> board){
        for(int j=0; j<9; j++){
            map<char,int> mp;
            for(int i=0; i<9; i++){
                if(board[i][j] != '.'){
                    mp[board[i][j]]++;
                }
            }
            for(auto it: mp){
                if(it.second >1){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkMat(vector<vector<char>> board){
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                map<char,int> mp;
                for(int k=i; k<i+3; k++){
                    for(int l=j; l<j+3; l++){
                        if(board[k][l] != '.'){
                            mp[board[k][l]]++;
                        }
                    }
                }
                for(auto it: mp){
                    if(it.second >1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        if(checkRow(board) and checkCol(board) and checkMat(board)) return true;
        return false;
    }
};