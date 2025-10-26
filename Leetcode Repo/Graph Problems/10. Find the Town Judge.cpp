/*
997. Find the Town Judge
https://leetcode.com/problems/find-the-town-judge/description/
 */

/*
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> out_deg(n+1),indeg(n+1);
        for(auto v : trust){
            out_deg[v[0]]++;
            indeg[v[1]]++;
        }

        for(int i=1;i<=n;i++){
            if(out_deg[i]==0 && indeg[i]==n-1) return i;
        }
        return -1;
    }
};
*/

// with one array only --- optimized

class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {

    vector<int> deg(n + 1);
    for (auto v : trust)
    {
      deg[v[0]]--;
      deg[v[1]]++;
    }

    for (int i = 1; i <= n; i++)
    {
      if (deg[i] == n - 1)
        return i;
    }
    return -1;
  }
};