1class Solution {
2public:
3    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
4        
5        int ans = 0;
6        int en = -1;
7        for(int i=0 ;i < timeSeries.size();i++){
8            
9            if(timeSeries[i] >= en){
10                ans += duration;   
11            }
12            else{
13                ans += (timeSeries[i] + duration - en);
14            }
15            en = timeSeries[i] + duration;
16        }
17        return ans;
18    }
19};