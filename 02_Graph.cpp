/* ********************************************************************
01. Clone a graph
*********************************************************************** */


/* ********************************************************************
02. DFS
*********************************************************************** */

vector<int> dfs(vector<vector<int>>& adj) {
    vector<int> ans;
    int V = adj.size();
    vector<bool> vis(V, false); // Visited Array

    for (int i = 0; i < V; i++) {
        if (vis[i] == false) {
            solve(i, vis, ans, adj);
        }
    }
    return ans;
}

void solve(int src,
           vector<bool>& vis,
           vector<int>& ans,
           vector<vector<int>>& adj) {
    vis[src] = true;
    ans.push_back(src);

    for (auto adjNode : adj[src]) {
        if (vis[adjNode] == false) {
            solve(adjNode, vis, ans, adj);
        }
    }
}

/* ********************************************************************
03. BFS
*********************************************************************** */

vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> ans;
    vector<bool> vis(V, false);

    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto adjNode : adj[node]) {
            if (vis[adjNode] == false) {
                vis[adjNode] = true;
                q.push(adjNode);
            }
        }
    }

    return ans;
}

/* ********************************************************************
04. Detect A cycle in Undirected Graph using BFS
*********************************************************************** */
// Intuition : queue(node, parent); If adjNode of node is visited, 
//                                 and it's not parent then cycle

bool isCycle(int V, vector<vector<int>>& edges) {
    // edge list to adjacency list
    vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (detect(i, visited, adj)) return true;
        }
    }
    return false;
}

bool detect(int index, vector<int>& visited, vector<vector<int>>& edges) {
    queue<pair<int, int>> q;
    q.push({index, -1});
    visited[index] = 1;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : edges[node]) {
            if (!visited[adjacentNode]) {
                visited[adjacentNode] = 1;
                q.push({adjacentNode, node});
            } else if (parent != adjacentNode) {
                return true;
            }
        }
    }
    return false;
}


/* ********************************************************************
05. Detect A cycle in Undirected Graph using DFS
*********************************************************************** */
// Intution : Recursive dfs(node, parent) & visit array

bool isCycle(int V, vector<vector<int>>& edges) {

    // edge-list to adjcency-list
    vector<vector<int>> adj(V);
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // disconnected-component
    vector<bool> vis(V, false);
    for(int i=0; i<V; i++) {
        if(vis[i]==false) {
            if(detect(i, -1, vis, adj))
                return true;
        }
    }
    return false;
}

bool detect(int node,
    int parent,
    vector<bool> &vis, 
    vector<vector<int>>& adj)
{
    vis[node] = true;

    for(auto adjNode : adj[node]) {
        if(vis[adjNode]==false) {
            if(detect(adjNode, node, vis, adj))
                return true;
        }
        else {
            if(adjNode!=parent)
                return true;
        }
    }
    return false;
}

/* ********************************************************************
06. Detect A cycle in Directed Graph using DFS
*********************************************************************** */

// Intution : Have vis[V] and visDfs[V], If both vis[node] and visDfs[node] is true     
                                                            // backtrack
bool isCyclic(int V, vector<vector<int>> &edges) {

    // edge-list to adjacency-list
    vector<vector<int>> adj(V);
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<bool> vis(V, false);
    vector<bool> visDfs(V, false);

    // Disconnected-Component
    for (int i = 0; i < V; i++) {
        if (vis[i] == false) {
            if (detect(i, vis, visDfs, adj))
                return true;
        }
    }
    return false;
}

                                                            
bool detect(int src,
            vector<bool> &vis,
            vector<bool> &visDfs,
            vector<vector<int>> &adj)
{
    vis[src] = true;
    visDfs[src] = true;

    for (auto adjNode : adj[src]) {
        if (vis[adjNode] == false) {
            if (detect(adjNode, vis, visDfs, adj))
                return true;
        } else {
            if (visDfs[adjNode] == true) {
                return true;
            }
        }
    }
    visDfs[src] = false;
    return false;
}

/* ********************************************************************
07. Detect A cycle in Directed Graph using BFS
*********************************************************************** */
// Intiution : Do TopoSort - kahn algo with a counter

bool isCyclic(int V, vector<vector<int>> &edges) {
       
    vector<vector<int>> adj(V);
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    
    vector<int> ans;
    vector<int> indegree(V, 0);
    
    for(int i=0; i<V; i++) {
       for(auto x : adj[i]) {
           indegree[x]++;
       }
    }
    
    queue<int> q;
    for(int i=0; i<V; i++)
        if(indegree[i]==0)
            q.push(i);
            
    int cnt=0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        cnt++;
        
        for(auto adjNode : adj[node]) 
        {
            indegree[adjNode]--;
            if(indegree[adjNode]==0)
                q.push(adjNode);
        }
        
    }
    if(cnt==V)
        return false;
    return true;
    
}



/* ********************************************************************
08. TOPO Sort - BFS - Kahn Algo
*********************************************************************** */
// Intution: Indegree array

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    vector<vector<int>> adj(V);
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    
    vector<int> ans;
    vector<int> indegree(V, 0);
    
    for(int i=0; i<V; i++) {
       for(auto x : adj[i]) {
           indegree[x]++;
       }
    }
    
    queue<int> q;
    for(int i=0; i<V; i++)
        if(indegree[i]==0)
            q.push(i);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto adjNode : adj[node]) 
        {
            indegree[adjNode]--;
            if(indegree[adjNode]==0)
                q.push(adjNode);
        }
        
    }
        
    return ans;
}

/* ********************************************************************
09. TOPO Sort - DFS
*********************************************************************** */
// Intution: When DFS is complete push back the element to stack

void dfs(int src, 
         stack<int> &stk, 
         vector<bool> &visited,
         vector<int> adj[]) {
    visited[src] = true;

    for (auto x : adj[src]) {
        if (visited[x] == false) {
            dfs(x, stk, visited, adj);
        }
    }
    stk.push(src);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    // code here
    stack<int> stk;
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (vis[i] == false) {
            dfs(i, stk, vis, adj);
        }
    }

    vector<int> ans;

    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}

/* ********************************************************************
10. No of Island
*********************************************************************** */
// Intution: DFS and drop the land

class Solution {
    public:
    
        void dfs(vector<vector<char>>& grid,
                   int i, int j,
                   int r, int c)
        {
            if(i<0 || j<0 || i>r-1 || j>c-1 || grid[i][j]=='0')
                return;
            
            grid[i][j]='0';
            dfs(grid, i+1, j, r, c);
            dfs(grid, i, j+1, r, c);
            dfs(grid, i-1, j, r, c);
            dfs(grid, i, j-1, r, c);
        }
        int numIslands(vector<vector<char>>& grid) {
            
            int r = grid.size();
            int c = grid[0].size();
    
            int cnt=0;
    
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    if(grid[i][j]=='1') {
                        dfs(grid, i, j, r, c);
                        cnt++;
                    }
                }
            }
            return cnt;
    
        }
    };


/* ********************************************************************
11. Bipartite
*********************************************************************** */
// Intution: color array(-1)

bool isBipart(int node,
              int paint,
              vector<int>& color,
              vector<vector<int>>& graph) {
    color[node] = paint;

    for (auto adjNode : graph[node]) {
        if (color[adjNode] == -1) {
            if (isBipart(adjNode, 1 - paint, color, graph) == false)
                return false;
        } else {
            if (color[adjNode] == paint)
                return false;
        }
    }

    return true;
}


bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (isBipart(i, 0, color, graph) == false)
                return false;
        }
    }
    return true;
}
