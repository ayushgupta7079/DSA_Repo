1class Solution {
2public:
3    int minSizeSubarray(vector<int>& nums, int target) {
4        
5        int n = nums.size();
6        long long sum =0;
7        vector<int> arr(2*n);
8        int i=0;
9        for(auto &v : nums) {
10            sum += v;
11            arr[i] = v;
12            arr[i+n]=v;
13            i++;
14        }
15
16        int rep = target/sum;
17        target %= sum;
18
19        int head=-1;
20        int tail=0;
21        int ans = 1e9;
22        long long cursum=0;
23        while(tail < 2*n){
24            while(head+1<2*n && cursum + arr[head+1] <= target){
25                head++;
26                cursum += arr[head];
27            }
28            if(target == cursum){
29                ans = min(ans, head-tail+1);
30            }
31            if(tail > head){
32                tail++;
33                head=tail-1;
34            }
35            else{
36                cursum -= arr[tail];
37                tail++;
38            }
39        }
40        return ans==1e9?-1:ans + rep*n;
41
42    }
43};