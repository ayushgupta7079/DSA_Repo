1class Solution {
2public:
3    vector<int> isValid(vector<int>& b,  int give, int sumA, int sumB){
4        int m = b.size();
5        int lo = 0;
6        int hi = m-1;
7        while(lo <= hi){
8            int mid = lo + (hi-lo)/2;
9            if(sumA + b[mid]*2 == sumB + 2*give){
10                return {1, b[mid]};
11            }
12            else if(sumA + b[mid]*2 > sumB + 2*give){
13                hi = mid-1;
14            }
15            else{
16                lo = mid+1;
17            }
18        }
19        return {0,-1};
20    }
21    // sumA - give + taken == sumB - take + give
22    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
23        
24        sort(aliceSizes.begin(),aliceSizes.end());
25        sort(bobSizes.begin(),bobSizes.end());
26
27        int n = aliceSizes.size();
28        int m = bobSizes.size();
29
30        int sumA = 0, sumB = 0;
31        for(auto v : aliceSizes){
32            sumA += v;
33        }
34        for(auto v : bobSizes){
35            sumB += v;
36        }
37
38        for(int i = 0; i < n; i++){
39            int give = aliceSizes[i];
40            vector<int> valid = isValid(bobSizes,give,sumA,sumB);
41            if(valid[0]){
42                return {give, valid[1]};
43            }
44        }
45        return {0,0};
46    }
47};