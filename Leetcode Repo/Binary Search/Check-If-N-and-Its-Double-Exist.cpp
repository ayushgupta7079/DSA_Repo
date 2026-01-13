1class Solution {
2public:
3    bool checkIfExist(vector<int>& arr) {
4        unordered_map<int,int> mp;
5        for(int i=0;i<arr.size();i++){
6            if(mp[2*arr[i]] || (arr[i]%2==0 && mp[arr[i]/2])) return true;
7            mp[arr[i]]=1;
8        }
9        return false;
10    }
11};