1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        
5        int i=0,j=0;
6        int n = nums.size();
7        for(int i=0;i<n;i++){
8            if(i==0 || nums[i]!=nums[i-1]){
9                nums[j]=nums[i];
10                j++;
11            }
12        }
13        return j;
14    }
15};