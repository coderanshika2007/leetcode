class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int primary = 0;
        int secondary = 0;
        int m = 0;
        int n = mat.size();
        for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
            if(i==j){
                primary += mat[i][j];
            }
            if(i+j == n-1){
                secondary += mat[i][j];
            }
            if(i==j  && i+j == n-1){
                m = mat[i][j];
            }
           }
        }
        int sum = primary + secondary - m;
        return sum;
    }
};