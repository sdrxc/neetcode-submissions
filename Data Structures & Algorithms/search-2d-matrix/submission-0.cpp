class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // if(matrix.size()==1 && matrix[0].size()==1 && matrix[0][0]==target)
        // {
        //     return true;
        // }
        
    
        for(int i =0;i<matrix.size();i++)
        {

        int low = 0, high = matrix[i].size() - 1;

        while (low <= high) {  // Corrected termination condition
            int mid = low + (high - low) / 2;  // Prevents overflow The safer way to calculate mid is:

            if (matrix[i][mid] == target) {
                return true;
            } 
            else if (matrix[i][mid] < target) {                
                low = mid + 1;  // Move right
            } 
            else {
                high = mid - 1;  // Move left
            }
        }
        }

        return false;
    }
};