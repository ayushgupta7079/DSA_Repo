1class Solution {
2public:
3    int largestInteger(int num) {
4        string v = to_string(num);
5
6        vector<int> e,o;
7        for(int i=0;i<v.size();i++){
8            if((v[i]-'0')%2){
9                o.push_back(v[i]-'0');
10            }
11            else{
12                e.push_back(v[i]-'0');
13            }
14        }
15
16        sort(e.rbegin(), e.rend());
17        sort(o.rbegin(), o.rend());
18
19        int ind1=0,ind2=0;
20
21        for(int i=0;i<v.size();i++){
22            int x = v[i]-'0';
23            if(x%2){
24                v[i] = (o[ind1] + '0');
25                ind1++;
26            }
27            else{
28                v[i] = (e[ind2] + '0');
29                ind2++;
30            }
31        }
32
33        return stoi(v);
34    }
35};