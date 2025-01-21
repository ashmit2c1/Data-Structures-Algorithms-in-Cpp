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
// FIND THE ARTICULATION POINT IN GRAPH BRUTE FORCE WAY 
void dfsFunction(int node,vector<int>adj[],vector<bool>&visited,int skip){
    visited[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor = adj[node][i];
        if(visited[neighbor]==false && neighbor!=skip){
            dfsFunction(neighbor,adj,visited,skip);
        }
    }
}
bool isGraphConnected(int V,vector<int>adj[],int node){
    vector<bool>visited(V,false);
    int start=-1;
    for(int i=0;i<V;i++){
        if(i!=node){
            start=i;
            break;
        }
    }
    if(start==-1){
        return false;
    }
    dfsFunction(start,adj,visited,node);
    for(int i=0;i>V;i++){
        if(i!=node && visited[i]==false){
            return false;
        }
    }
    return true;
}
vector<int>findArticulationsPoint(int V,vector<int>adj[]){
    vector<int>ans;
    for(int i=0;i<V;i++){
        if(isGraphConnected(V,adj,i)==false){
            ans.push_back(i);
        }
    }
    return ans;
}
// FIND THE ARTICULATION POINT IN GRAPH OPTIMISED WAY
void dfsArtPoint(int node,int parent,vector<int>adj[],vector<bool>&visited,vector<int>&discovery,vector<int>&low,vector<bool>&artPoints,int &count){
    visited[node]=true;
    discovery[node]=low[node]=count++;
    int n=adj[node].size();
    int child=0;
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(neighbor==parent){
            continue;
        }
        if(visited[neighbor]==true){
            low[node]=min(low[node],discovery[neighbor]);
        }
        else{
            child++;
            dfsArtPoint(neighbor,node,adj,visited,discovery,low,artPoints,count);
            low[node]=min(low[node],low[neighbor]);
            if(discovery[node] <= low[neighbor] && parent!=-1){
                artPoints[node]=true;
            }
        }
        if(parent==-1 && child>1){
            artPoints[node]=true;
        }
    }
}
vector<int>findPoints(int V, vector<int>adj[]){
    vector<int>discovery(V,-1);
    vector<int>low(V,-1);
    vector<bool>artPoints(V,false);
    vector<bool>visited(V,false);
    int count=0;
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfsArtPoint(i,-1,adj,visited,discovery,low,artPoints,count);
        }
    }
    vector<int>ans;
    for(int i=0;i<artPoints.size();i++){
        if(artPoints[i]==true){
            ans.push_back(i);
        }
    }
    return ans;
}
// BRIDGES IN GRAPH BRUTE FORCE WAY 
void dfs(int node,vector<int>adj[],vector<bool>&visited){
    visited[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfs(neighbor,adj,visited);
        }
    }
}
bool isConnected(vector<int>adj[],int V){
    vector<bool>visited(V,false);
    dfs(0,adj,visited);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            return false;
        }
    }
    return true;
}
vector<vector<int>>criticalConnections(int V,vector<int>adj[]){
    vector<vector<int>>ans;
    for(int u=0;u<V;u++){
        for(int v:adj[u]){
            if(u<v){
                adj[u].erase(find(adj[u].begin(),adj[u].end(),v));
                adj[v].erase(find(adj[v].begin(),adj[v].end(),u));
                if(isConnected(adj,V)==false){
                    ans.push_back({u,v});
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
    }
    return ans;
}
// BRIDGES IN GRAPH OPTIMISED WAY


// PATH WITH MIN EFFORT 
bool isValid(int x,int y,vector<vector<int>>&matrix){
    if(x>=0 && y>=0 && x<matrix.size() && y<matrix[0].size()){
        return true;
    }
    return false;
}
int minimumEffortPath(vector<vector<int>>&matrix){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<vector<int>>efforts(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
    efforts[0][0]=0;
    pq.push({0,{0,0}});
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,-1,1};
    while(pq.empty()==false){
        int currentX = pq.top().second.first;
        int currentY = pq.top().second.second;
        int currentEffort = pq.top().first;
        pq.pop();
        if(currentX == matrix.size()-1 && currentY== matrix[0].size()-1){
            return currentEffort;
        }
        pq.pop();
        for(int i=0;i<4;i++){
            int newX = currentX + rows[i];
            int newY = currentY + cols[i];
            if(isValid(newX,newY,matrix)==true){
                int diff = abs(matrix[newX][newY]-matrix[currentX][currentY]);
                int newEffort = max(currentEffort,diff);
                if(efforts[newX][newY] > newEffort){
                    efforts[newX][newY] = newEffort; 
                    pq.push({newEffort,{newX,newY}});
                }
            }
        }
    }
    return -1;
}
// PATH WITH MAXIMUM PROBABILITY 
double pathWithMaxProb(int n,int start_node,int end_node,vector<double>prob,vector<vector<int>>&edges){
    vector<vector<pair<double,int>>>adj(n);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        double probs = prob[i];
        adj[u].push_back({probs,v});
        adj[v].push_back({probs,u});
    }
    vector<double>maxprob(n,0.0);
    maxprob[start_node]=1.0;
    priority_queue<pair<double,int>>pq;
    pq.push({1.0,start_node});
    while(pq.empty()==false){
        double currentprob = pq.top().first;
        double currentnode = pq.top().second;
        pq.pop();
        if(currentnode==end_node){
            return currentprob;
        }
        int n=adj[currentnode].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[currentnode][i].second;
            double probss = adj[currentnode][i].first;
            double newprob = probss*currentprob;
            if(newprob > maxprob[neighbor]){
                maxprob[neighbor]=newprob;
                pq.push({newprob,neighbor});
            }
        }
    }
    return 0;
}
// COVID SPREAD
bool isValid(int x,int y,int r,int c,vector<vector<int>>&matrix){
    if(x>=0 && y>=0 && x < r && y < c && matrix[x][y]==1){
        return true;
    }
    return false;
}
int covidspread(vector<vector<int>>&matrix){
    int r=matrix.size();
    int c=matrix[0].size();
    queue<pair<int,int>>q;
    int count=0;
    for(int i = 0; i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]==2){
                q.push({i,j});
            }
        }
    }
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,-1,1};
    while(q.empty()==false){
        int n=q.size();
        bool spread=false;
        while(n--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newX = x + rows[i];
                int newY = y + cols[i];
                if(isValid(newX,newY,r,c,matrix)==true){
                    matrix[newX][newY]=2;
                    q.push({newX,newY});
                    spread=true;
                }
            }
        }
        if(spread==true){
            count++;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]==1){
                return -1;
            }
        }
    }
    return count;
}
// FIND THE NUMBER OF ISLANDS IN A GRAPH 
bool isValid(int x,int y,int r,int c,vector<vector<int>>&matrix){
    if(x>=0 && y>=0 && x<r && y<c && matrix[x][y]==1){
        return true;
    }
    return false;
}
int numIslands(vector<vector<int>>&matrix){
    int r=matrix.size();
    int c=matrix[0].size();
    queue<pair<int,int>>q;
    int count=0;
    int rows[8]={-1,-1,-1,1,1,1,0,0};
    int cols[8]={-1,0,1,-1,0,1,-1,1};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int value = matrix[i][j];
            if(value==1){
                q.push({i,j});
                count++;
                matrix[i][j]=0;
                while(q.empty()==false){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int k=0;k<8;k++){
                        int newX = x + rows[k];
                        int newY = y + cols[k];
                        if(isValid(newX,newY,r,c,matrix)==true){
                            matrix[newX][newY]=0;
                            q.push({newX,newY});
                        }
                    }
                }
            }
        }
    }
    return count; 
}
// COURSE SCHEDULER 
bool isPossible(int N,int M,vector<pair<int,int>>&tasks){
    vector<vector<int>>adj(N);
    for(int i=0;i<M;i++){
        int u=tasks[i].first;
        int v=tasks[i].second;
        adj[u].push_back(v);
    }
    vector<int>indegree(N,0);
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();i++){
            int node=adj[i][j];
            indegree[node]++;
        }
    }
    queue<int>q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(q.empty()==false){
        int node=q.front();
        ans.push_back(node);
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    if(ans.size()!=N){
        return false;
    }else{
        return true;
    }
}
// PARALLEL COURSES 3 
int minimumTime(int N,vector<int>&time,vector<vector<int>>relations){
    vector<int>mintime(N,0);
    vector<int>indegree(N,0);
    vector<vector<int>>adj(N);
    for(int i=0;i<relations.size();i++){
        int u = relations[i][0]-1;
        int v = relations[i][1]-1;
        adj[u].push_back(v);
    }
    for(int i=0;adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            int node=adj[i][j];
            indegree[node]++;
        }
    }
    queue<int>q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
            mintime[i]=time[i];
        }
    }
    while(q.empty()==false){
        int node=q.front();
        q.pop();
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            mintime[neighbor]=max(mintime[neighbor],mintime[node]+time[neighbor]);
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    return *max_element(mintime.begin(),mintime.end());
}
// SHORTEST DISTANCE FROM SOURCE TO DESTINATION 
bool isValid(int x,int y,int N,int M,vector<vector<int>>&matrix){
    if(x>=0 && y>=0 && x < N && y < M && matrix[x][y]==1){
        return true;
    }
    return false;
}
int shortestDistance(int N,int M,vector<vector<int>>&matrix,int X,int Y){
    int r=matrix.size();
    int c=matrix[0].size();
    if(matrix[0][0]==0 || matrix[X][Y]==0){
        return -1;
    }
    queue<pair<pair<int,int>,int>>q;
    vector<vector<bool>>visited(N,vector<bool>(M,false));
    visited[0][0]=true;
    q.push({{0,0},0});
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,-1,1};
    while(q.empty()==false){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int step = q.front().second;
        q.pop();
        if(x==X && y==Y){
            return step;
        }
        for(int i=0;i<4;i++){
            int newX = x + rows[i];
            int newY = y + cols[i];
            if(isValid(newX,newY,N,M,matrix)==true){
                visited[newX][newY]=true;
                q.push({{newX,newY},step+1});
            }
        }
    }
    return -1;
}
// KNIGHT WALK 
bool isValid(int x,int y,int n){
    if(x>=0 && y>=0 && x < n  && y < n ){
        return true;
    }
    return false;
}
int minsteptoreachtarget(vector<int>&knightPos,vector<int>&targetPos,int N){
    if(knightPos[0]==targetPos[0] && knightPos[1]==targetPos[1]){
        return 0;
    }
    queue<pair<int,int>>q;
    vector<vector<bool>>visited(N,vector<bool>(N,false));
    visited[knightPos[0]][knightPos[1]]=true;
    q.push({knightPos[0],knightPos[1]});
    int step=0;
    int row[8]={2,2,-2,-2,1,-1,1,-1};
    int col[8]={1,-1,1,-1,2,2,-2,-2};
    while(q.empty()==false){
        int cnt=q.size();
        while(cnt--){
            int x=q.front().first;
            int y=q.front().second;
            if(x==targetPos[0] && y==targetPos[1]){
                return step;
            }
            q.pop();
            for(int i=0;i<8;i++){
                int newX = x+row[i];
                int newY = y+col[i];
                if(isValid(newX,newY,N)==true && visited[newX][newY]==false){
                    visited[newX][newY]=true;
                    q.push({newX,newY});
                }
            }
        }
        step++;
    }
    return -1;
}

