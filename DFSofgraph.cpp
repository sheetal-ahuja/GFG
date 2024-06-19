class Solution {
  public:
  
  void DFS(unordered_map<int, vector<int>> &adj, int u,vector<bool> &visited, vector<int>&result)
  {
      if(visited[u]==true){
          return ;
      }
      
      visited[u]=true;
      result.push_back(u);
      
      for(int & v: adj[u]){
          if(!visited[v]){
              DFS(adj,v,visited,result);
          }
      }
  }
  
  
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> mp[]) {
        // Code here
        unordered_map<int, vector<int>> adj;
        
        for(int u=0;u<v;u++)
        {
            for(auto v= mp[u].begin(); v!=mp[u].end();v++)
            {
                adj[u].push_back(*v);            
            }
        }
        
        vector<int> result;
        vector<bool>visited(v,false);
        
        
        DFS(adj,0,visited,result);
        return result;
        
    }
};
