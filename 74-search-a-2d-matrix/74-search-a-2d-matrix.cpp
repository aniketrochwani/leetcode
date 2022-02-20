class Solution {
public:
    bool bs(vector<int> mat, int target){
        int low = 0;
        int high = mat.size()-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(mat[mid] == target) return true;
            else if(mat[mid] > target) high = mid-1;
            else low = mid+1;
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int count=0;
        for(int i=0; i<matrix.size(); i++){
            vector<int> current = matrix[i];
            if(bs(current, target)) count++;
        }
        if(count > 0 )return true;
        return false;
    }
};