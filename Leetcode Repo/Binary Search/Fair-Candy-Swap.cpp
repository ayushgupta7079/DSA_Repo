1class Solution {
2public:
3// sumA - gu=ive + take = sumB- take + give -==> take = (sumB-sumA + 2*give)/2
4    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
5        
6
7        int n = aliceSizes.size();
8        int m = bobSizes.size();
9        unordered_map<int,int> mp;
10
11        int sumA = 0, sumB = 0;
12        for(auto v : aliceSizes){
13            sumA += v;
14        }
15        for(auto v : bobSizes){
16            sumB += v;
17            mp[v] = 1;
18        }
19
20        for(int i = 0; i < n; i++){
21            int a = aliceSizes[i];
22            int req = (sumB-sumA + 2*a)/2;
23            if(mp[req]){
24                return {a,req};
25            }
26        }
27        return {0,0};
28    }
29};