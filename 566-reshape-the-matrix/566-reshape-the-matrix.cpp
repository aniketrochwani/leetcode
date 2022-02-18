class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size()*mat[0].size() != r*c) return mat;
        
        vector<int> p(c,0);
        vector<vector<int>> ans(r,p);
        vector<int> temp;
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                temp.push_back(mat[i][j]);   
            }
        }
        
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans[i][j] = temp[0];
                temp.erase(temp.begin());
            }
        }
        
        return ans;
    }
};