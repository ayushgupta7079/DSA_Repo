/*
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
*/

class Solution
{
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
  {

    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)
      dist[i][i] = 0;
    for (auto v : edges)
    {
      int i = v[0];
      int j = v[1];
      int w = v[2];
      dist[i][j] = min(dist[i][j], w);
      dist[j][i] = min(dist[j][i], w);
    }

    for (int via = 0; via < n; via++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          dist[i][j] = min(dist[i][via] + dist[via][j], dist[i][j]);
        }
      }
    }

    int ans = 1e9;
    int node = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      int count = 0;
      for (int j = 0; j < n; j++)
      {
        if (i != j && dist[i][j] <= distanceThreshold)
        {
          count++;
        }
      }
      if (count < ans)
      {
        ans = count;
        node = i;
      }
    }
    return node;
  }
};