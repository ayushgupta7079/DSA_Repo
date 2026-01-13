1class Solution {
2public:
3
4    bool searchMatrix(vector<vector<int>>& matrix, int target) {
5        
6        int m = matrix.size();
7        int n = matrix[0].size();
8
9        int r = 0, c = n-1;
10
11        while(r < m && c >= 0){
12
13            if(matrix[r][c] == target) return true;
14            else if(matrix[r][c] > target){
15                c--;
16            }
17            else{
18                r++;
19            }
20        }
21        return false;
22    }
23};