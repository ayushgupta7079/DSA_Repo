/*
1971. Find if Path Exists in Graph
link - https://leetcode.com/problems/find-if-path-exists-in-graph/
*/

class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int> &vis){
        vis[node]=1;
        for(auto v : adj[node]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);
        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<int> vis(n,0);
        dfs(source,adj,vis);
        if(vis[destination]) return true;
        return false;
    }
};