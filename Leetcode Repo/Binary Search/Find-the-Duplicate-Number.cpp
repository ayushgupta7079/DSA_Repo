1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        
5       int slow = 0;
6       int fast = 0;
7
8       do{
9        slow = nums[slow];
10        fast = nums[nums[fast]];
11       } while(slow!=fast);
12
13       slow = 0;
14       while(slow!=fast){
15        slow = nums[slow];
16        fast= nums[fast];
17       }
18
19       return slow;
20    }
21};