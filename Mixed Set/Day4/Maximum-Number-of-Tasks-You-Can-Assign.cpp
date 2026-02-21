1class Solution {
2public:
3    int n;
4    bool check(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength){
5
6        multiset<int> ws;
7        // take strongest mid workers
8        for (int i = 0; i < mid; i++) {
9            ws.insert(workers[i]);
10        }
11
12        // process hardest tasks first
13        for (int i = mid - 1; i >= 0; i--) {
14            int task = tasks[i];
15
16            // try without pill
17            auto it = ws.lower_bound(task);
18            if (it != ws.end()) {
19                ws.erase(it);
20            } else {
21                // need pill
22                if (pills == 0) return false;
23
24                // find weakest worker who can do task with pill
25                it = ws.lower_bound(task - strength);
26                if (it == ws.end()) return false;
27
28                ws.erase(it);
29                pills--;
30            }
31        }
32
33        return true;
34    
35    }
36    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
37        n = tasks.size();
38        int m = workers.size();
39        int lo = 0;
40        int hi = min(n,m);
41        sort(tasks.begin(), tasks.end());
42        sort(workers.rbegin(), workers.rend());
43        while(lo <= hi){
44            int mid = lo + (hi - lo)/2;
45
46            if(check(mid, tasks, workers, pills, strength)){
47                lo = mid+1;
48            }
49            else{
50                hi = mid-1;
51            }
52        }
53        return hi;
54    }
55};