/*
433. Minimum Genetic Mutation
https://leetcode.com/problems/minimum-genetic-mutation/description/
*/

// Solution - 1

class Solution
{
public:
  int minMutation(string startGene, string endGene, vector<string> &bank)
  {

    map<string, int> mp;
    map<int, string> mp2;

    int id = 0;
    mp[startGene] = id;
    mp2[id++] = startGene;
    for (auto v : bank)
    {
      mp[v] = id;
      mp2[id++] = v;
    }
    // when endGene is not present in Bank -- > No solution
    if (mp.find(endGene) == mp.end())
      return -1;

    vector<int> dist(id, 1e9);
    queue<int> q;
    dist[0] = 0;
    q.push(0);

    int size = startGene.length();
    vector<char> seq = {'A', 'C', 'G', 'T'};

    while (!q.empty())
    {
      int node = q.front();
      string cur = mp2[node];
      q.pop();

      for (int i = 0; i < size; i++)
      {
        string neigh = cur;
        for (int k = 0; k < 4; k++)
        {
          if (seq[k] == cur[i])
            continue;
          neigh[i] = seq[k];
          if (mp.find(neigh) != mp.end())
          {
            if (dist[mp[neigh]] > dist[node] + 1)
            {
              dist[mp[neigh]] = dist[node] + 1;
              q.push(mp[neigh]);
            }
          }
        }
      }
    }
    if (dist[mp[endGene]] != 1e9)
      return dist[mp[endGene]];
    return -1;
  }
};

/*
Soltuion - 2

class Solution {
public:
    bool valid(string a,string b){
        int count = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) count++;
        }
        return count == 1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        map<string,int> mp;
        map<int,string> mp2;
        int id = 0;
        mp[startGene] = id;
        mp2[id++] = startGene;
        for(auto v : bank){
            mp[v] = id;
            mp2[id++] = v;
        }
        if(mp[endGene]==0) return -1;
        queue<int> q;
        vector<int> dist(id,1e9);
        dist[0] = 0;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto v : bank){
                int neigh = mp[v];
                string cur = mp2[node];
                if(cur == v) continue;
                if(valid(cur,v)){
                    if(dist[neigh] > dist[node] + 1){
                        dist[neigh] = dist[node] + 1;
                        q.push(neigh);
                    }
                }
            }
        }
        if(dist[mp[endGene]]!=1e9) return dist[mp[endGene]];
        return -1;
    }
};
*/