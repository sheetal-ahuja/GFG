// problem link -> https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/0

class Solution {
  public:
  
  void BFS(unordered_map<int ,vector<int>> &adj, int u, vector<bool>&visited,vector<int>&result)
  {
      queue<int> que;
      que.push(u);
      visited[u]=true;
      result.push_back(u);
      
      while(!que.empty()){
          int u=que.front();
          que.pop();
          
          for(int &v:adj[u])
          {
              if(!visited[v]){
                  que.push(v);
                  visited[v]=true;
                  result.push_back(v);
              }
          }
      }
  }
  
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> mp[]) {
        // Code here
    unordered_map<int, vector<int>> adj;
    for(int u=0;u<v;u++)
    {
        for(auto v= mp[u].begin();v!=mp[u].end();v++)
        {
            adj[u].push_back(*v);
        }
    }
    
    vector<bool>visited(v,false);
    vector<int>result;
    
    BFS(adj,0,visited, result);
    
    return result;
    }
};
