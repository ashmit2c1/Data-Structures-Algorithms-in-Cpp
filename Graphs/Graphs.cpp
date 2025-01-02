#include<bits/stdc++.h>
using namespace std;
// BREADTH FIRST SEARCH 
vector<int>bfsTraversal(int V,vector<int>adj[]){
    vector<bool>visited(V,false);
    vector<int>ans;
    queue<int>q;
    q.push(0);
    visited[0]=true;
    while(q.empty()==false){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            if(visited[neighbor]==false){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
    return ans;
}

// DEPTH FIRST SEARCH
void dfsFunction(int node,vector<bool>&visited,vector<int>&ans,vector<int>adj[]){
    visited[node]=true;
    ans.push_back(node);
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsFunction(neighbor,visited,ans,adj);
        }
    }
}
vector<int>dfsTraversal(int V,vector<int>adj[]){
    vector<bool>visited(V,false);
    vector<int>ans;
    int start=0;
    dfsFunction(start,visited,ans,adj);
    return ans;
}

// CYCLE DETECTION IN UNDIRECTED GRAPH USING DFS
bool checkForCycle(int node,int parent,vector<bool>&visited,vector<int>adj[]){
    visited[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(parent==neighbor){
            continue;
        }
        if(visited[neighbor]==true){
            return true;
        }
        if(visited[neighbor]==false){
            if(checkForCycle(neighbor,node,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V,vector<int>adj[]){
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(checkForCycle(i,-1,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}

// CYCLE DETECTION IN UNDIRECTED GRAPH USING BFS
bool checkForCycle(int node,vector<bool>&visited,vector<int>adj[]){
    queue<pair<int,int>>q;
    visited[node]=true;
    q.push({node,-1});
    while(q.empty()==false){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            if(neighbor==parent){continue;}
            if(visited[neighbor]==true){
                return true;
            }
            if(visited[neighbor]==false){
                visited[neighbor]=true;
                q.push({neighbor,node});
            }
        }
    }
    return false;
}
bool isCycle(int V,vector<int>adj[]){
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(checkForCycle(i,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}

// TOPOLOGICAL SORT 
void topoSortFunction(int node,vector<bool>&visited,stack<int>&st,vector<int>adj[]){
    visited[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[i]==false){
            topoSortFunction(neighbor,visited,st,adj);
        }
    }
    st.push(node);
}
vector<int>topoSort(int V,vector<int>adj[]){
    vector<bool>visited(V,false);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            topoSortFunction(i,visited,st,adj);
        }
    }
    vector<int>ans;
    while(st.empty()==false){
        int node=st.top();
        ans.push_back(node);
        st.pop();
    }
    return ans;
}

// TOPOLOGICAL SORT USING KAHNS ALGORITHMS 
vector<int>kahnsAlgorithm(int V,vector<int>adj[]){
    vector<int>ans;
    vector<int>inDegree(V,-1);
    for(int i=0;i<V;i++){
        int sz=adj[i].size();
        for(int j=0;j<sz;j++){
            int node=adj[i][j];
            inDegree[node]++;
        }
    }
    queue<int>q;
    for(int i=0;inDegree.size();i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(q.empty()==false){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            inDegree[neighbor]--;
            if(inDegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    return ans;
}

// DETECT A CYCLE IN DIRECTED GRAPH 
bool checkForCycle(int node,vector<bool>&visited,vector<bool>&path,vector<int>adj[]){
    visited[node]=true;
    path[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(path[neighbor]==true){
            return true;
        }
        if(visited[neighbor]==true){
            continue;
        }
        if(visited[neighbor]==false){
            if(checkForCycle(neighbor,visited,path,adj)==true){
                return true;
            }
        }
    }
    path[node]=false;
    return false;
}
bool isCycle(int V,vector<int>adj[]){
    vector<bool>visited(V,false);
    vector<bool>path(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(checkForCycle(i,visited,path,adj)==true){
                return true;
            }
        }
    }
    return false;
}

// DETECT CYCLE IN GRAPH USING KAHNS ALGORITHM
bool isCycle(int V,vector<int>adj[]){
    vector<int>ans;
    vector<int>inDegree(V,0);
    for(int i=0;i<V;i++){
        int sz=adj[i].size();
        for(int j=0;j<sz;j++){
            int node=adj[i][j];
            inDegree[node]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    while(q.empty()==false){
        int node=q.front();
        ans.push_back(node);
        int n=adj[node].size();
        q.pop();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            inDegree[neighbor]--;
            if(inDegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    int cnt=ans.size();
    if(cnt!=V){
        return true;
    }
    else{
        return false;
    }
}

// FIND THE SHORTEST DISTANCE FROM THE SOURCE NODE TO ALL NODES IN UNDIRECTED GRAPH 
vector<int>shortestPath(int N,int M,vector<vector<int>>&edges,int src){
    vector<vector<int>>adj(N);
    for(int i=0;i<M;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>distance(N,-1);
    vector<int>visited(N,false);
    queue<int>q;
    distance[src]=0;
    visited[src]=true;
    q.push(src);
    while(q.empty()==false){
        int node=q.front();
        q.pop();
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            if(visited[neighbor]==true){
                continue;
            }
            else{
                visited[neighbor]=true;
                distance[neighbor]=1+distance[node];
                q.push(neighbor);
            }
        }
    }
    return distance;
}


// FIND THE SHORTEST DISTANCE FROM A SOURCE NODE  TO ALL NODES IN DIRECTED ACYCLIC WEIGHTED GRAPH
void topoSortFunction(int node,vector<bool>&visited,stack<int>&st,vector<pair<int,int>>adj[]){
    visited[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i].first;
        if(visited[neighbor]==false){
            topoSortFunction(neighbor,visited,st,adj);
        }
    }
    st.push(node);
}
vector<int>shortestPathDAG(vector<vector<int>>edges,int N,int M,int src){
    vector<pair<int,int>>adj[N];
    for(int i=0;i<M;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int weight=edges[i][2];
        adj[u].push_back({v,weight});
    }
    stack<int>st;
    vector<bool>visited(N,false);
    topoSortFunction(0,visited,st,adj);
    vector<int>distance(N,INT_MAX);
    distance[src]=0;
    while(st.empty()==false){
        int node=st.top();
        st.pop();
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i].first;
            int weight=adj[node][i].second;
            distance[neighbor]=min(distance[neighbor],weight+distance[node]);
        }
    }
    for(int i=0;distance.size();i++){
        if(distance[i]==INT_MAX){
            distance[i]=-1;
        }
    }
    return distance;
}

// CHECK WHETHER THE GRAPH IS BIPARITE USING DFS
bool check(int node,vector<int>&color,vector<int>adj[]){
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(color[neighbor]==-1){
            color[neighbor]=1-color[node];
            if(check(neighbor,color,adj)==false){
                return false;
            }
        }
        else{
            if(color[neighbor]==color[node]){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V,vector<int>adj[]){
    vector<int>color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            color[i]=0;
            if(check(i,color,adj)==false){
                return false;
            }
        }
    }
    return true;
}
// FIND THE MINIMUM SPANNING TREE USING PRIMS ALGORITHM 
int spanningTreePRIMS(int V,vector<vector<int>>adj[]){
    vector<bool>isMST(V,false);
    vector<int>par(V);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,-1}});
    int totalCost=0;
    while(pq.empty()==false){
        int weight = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if(isMST[node]==false){
            isMST[node]=true;
            par[node]=parent;
            totalCost+=weight;
            int n=adj[node].size();
            for(int i=0;i<n;i++){
                int weight = adj[node][i][1];
                int neighbor=adj[node][i][0];
                pq.push({weight,{neighbor,node}});
            }
        }
    }
    return totalCost;
}
// FIND THE MINIMUM SPANNING TREE USING KRUSKAL ALGORITHM 
int findParent(int node,vector<int>&parent){
    if(parent[node]==node){
        return node;
    }
    else{
        parent[node]=findParent(parent[node],parent);
    }
}
void unionByrank(int u,int v,vector<int>&parent,vector<int>&rank){
    int parentU = findParent(u,parent);
    int parentV = findParent(v,parent);
    if(rank[parentU] > rank[parentV]){
        parent[parentV]=parentU;
    }
    else if(rank[parentU] < rank[parentV]){
        parent[parentU]=parentV;
    }
    else{
        parent[parentU]=parentV;
        rank[parentV]++;
    }
}
int spanningTreeKRUSKAL(int V,vector<vector<int>>adj[]){
    vector<int>parent(V);
    vector<int>rank(V,0);
    for(int i=0;i<V;i++){
        parent[i]=i;
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    for(int i=0;i<V;i++){
        int n=adj[i].size();
        for(int j=0;j<n;j++){
            int neighbor=adj[i][j][0];
            int weight=adj[i][j][1];
            pq.push({weight,{i,neighbor}});
        }
    }
    int cost = 0;
    int edges =0 ;
    while(pq.empty()==false && edges < V-1){
        int weight = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        if(findParent(u,parent)!=findParent(v,parent)){
            cost+=weight;
            edges++;
            unionByrank(u,v,parent,rank);
        }
    }
    return cost;
}
