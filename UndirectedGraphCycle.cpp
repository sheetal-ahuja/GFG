// problem link -> https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0

-------------------------------------------------------------------------------------------------------
                       DFS APPROACH
-------------------------------------------------------------------------------------------------------
  
  bool iscycleDFS(vector<int> adj[], int u, vector<bool>& visited, int parent)
  {
      visited[u]=true;
      
      for(int &v : adj[u])
      {
          if(v==parent)
          {
              continue;
          }
          if(visited[v])
          {
              return true;
          }
          if(iscycleDFS(adj, v, visited,u))
          {
              return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool> visited(v, false);
        for(int i =0; i<v; i++)
        {
            if(!visited[i] && iscycleDFS(adj, i,visited, -1))
            {
                return true;
            }
        }
        return false;
    }
-------------------------------------------------------------------------------------------------------
                       BFS APPROACH
-------------------------------------------------------------------------------------------------------
bool iscycleBFS(vector<int> adj[], int u , vector<bool>&visited){
    queue<pair<int , int>> que;
    
    que.push({u,-1});
    visited[u]= true;
    
    while(!que.empty())
    {
        pair<int ,int> p = que.front();
        que.pop();
        
        int source = p.first;
        int parent = p.second;
        
        for(int &v: adj[source]){
            if(visited[v]==false){
                visited[v]=true;
                que.push({v,source});
            }
            else if (v!=parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[])
{
    vector<bool>visited(v, false);
    
    for(int i=0; i<v; i++)
    {
        if(!visited[i]&&iscycleBFS(adj,i,visited))
        {
            return true;
        }
    }
    return false;
}
