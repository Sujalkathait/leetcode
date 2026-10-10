class Solution {
public:

   bool solve(int node, int destination,
               vector<vector<int>>& adj,
               vector<bool>& visited)
    {
      visited[node]=1;
      if(node==destination)
    {
        return true ;

    }
     for (int j = 0; j < adj[node].size(); j++)
        {
        int neighbor= adj[node] [j];
        if(!visited[neighbor])
        {

            if (solve(neighbor, destination, adj, visited))
                {
                    return true;
                }
        }
          
        }
        return false;

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
     {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, 0);

        return solve(source, destination, adj, visited);
    }
};