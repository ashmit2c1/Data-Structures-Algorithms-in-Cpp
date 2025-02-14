#include<bits/stdc++.h>
using namespace std;
// DEPTH FIRST SEARCH IN TREE / GRAPH 
void dfsfunction(int node,vector<bool>&visited,vector<int>&ans,vector<vector<int>>adj){
    visited[node]=true;
    int n=adj[node].size();
    ans.push_back(node);
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsfunction(neighbor,visited,ans,adj);
        }
    }
}
vector<int>dfstraversal(int V,vector<vector<int>>adj){
    vector<int>ans;
    vector<bool>visited(V,false);
    int start=0;
    dfsfunction(start,visited,ans,adj);
    return ans;
}
// BREADTH FIRST SEARCH IN TREE /GRAPH 
vector<int>bfstraversal(int V,vector<vector<int>>adj){
    vector<int>ans;
    vector<bool>visited(V,false);
    queue<int>q;
    q.push(0);
    visited[0]=0;
    while(q.empty()==false){
        int node=q.front();
        q.pop();
        ans.push_back(node);
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
// GIVEN A TREE COUNT THE NUMBER OF LEAF NODES 
void dfsfunction(int node,int&leaf,vector<bool>&visited,vector<vector<int>>adj){
    bool isleaf=true;
    int n=adj[node].size();
    visited[node]=true;
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            isleaf=false;
            dfsfunction(neighbor,leaf,visited,adj);
        }
    }
    if(isleaf==true){
        leaf++;
    }
}
int findLeaf(int V,vector<vector<int>>adj){
    int start=0;
    int leaf=0;
    vector<bool>visited(V,false);
    dfsfunction(start,leaf,visited,adj);
    return leaf;
}
// GIVEN AN UNDIRECTED TREE, FIND THE HEIGHT OF THE TREE 
void dfsfunction(int node,int&depth,int d,vector<bool>&visited,vector<vector<int>>adj){
    visited[node]=true;
    int n=adj[node].size();
    depth=max(depth,d);
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsfunction(node,depth,d+1,visited,adj);
        }
    }
}
int findHeight(int V,vector<vector<int>>adj){
    int depth=0;
    int start=0;
    vector<bool>visited(V,false);
    dfsfunction(start,depth,0,visited,adj);
    return depth;
}
// GIVEN AN UNDIRECTED TREE FIND ALL THE NODE THAT ARE PRESENT ON LEVEL K
void dfsfunction(int node,int level,int K,vector<int>&ans,vector<bool>&visited,vector<vector<int>>adj){
    visited[node]=true;
    int n=adj[node].size();
    if(level==K){
        ans.push_back(node);
    }
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsfunction(node,level+1,K,ans,visited,adj);
        }
    }
}
vector<int>findNodes(int V,vector<vector<int>>adj,int K){
    vector<int>ans;
    vector<bool>visited(V,false);
    int start=0;
    dfsfunction(start,0,K,ans,visited,adj);
    sort(ans.begin(),ans.end());
    return ans;
}
// GIVEN A GRAPH FIND THE NUMBER OF NEIGHBORS OF A NODE
int findNeighbors(int V,vector<vector<int>>adj,int node){
    return adj[node].size();
}
// GIVEN A GRAPH AND A TRAGET SUM, FIND IF THERE IS ANY PATH FROM ROOT TO LEAF NODE THAT HAS THE SUM 
void dfsfunction(int node,int current,int sum,bool&foundPath,vector<bool>&visited,vector<vector<int>>adj){
    visited[node]=true;
    current+=node;
    int n=adj[node].size();
    bool isLeaf=false;
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            isLeaf=false;
            dfsfunction(neighbor,current,sum,foundPath,visited,adj);
        }
    }
    if(isLeaf==true && current==sum){
        foundPath=true;
    }
}
bool findPath(int V,vector<vector<int>>&adj,int sum){
    bool foundPath=false;
    vector<bool>visited(V,false);
    int start=0;
    dfsfunction(start,0,sum,foundPath,visited,adj);
    return foundPath;
}
// GIVEN AN UNDIRECTED TREE, FIND THE SUM OF ALL SUBTREE NODES
void dfsfunction(int node,vector<int>&ans,vector<bool>&visited,vector<vector<int>>adj){
    visited[node]=true;
    int n=adj[node].size();
    ans[node]=node;
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsfunction(node,ans,visited,adj);
            ans[node]+=ans[neighbor];
        }
    }
}
vector<int>findsum(int V,vector<vector<int>>adj){
    vector<bool>visited(V,false);
    vector<int>ans(V,0);
    int start=0;
    dfsfunction(start,ans,visited,adj);
    return ans;
}
// GIVEN  A TREE FIND THE DIAMETER OF THE TREE 
pair<int,int>bfsfunction(int start,int V,vector<vector<int>>adj){
    vector<int>distance(V,-1);
    queue<int>q;
    q.push(start);
    distance[start]=0;
    while(q.empty()==false){
        int node=q.front();
        q.pop();
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            if(distance[neighbor]==-1){
                distance[neighbor]=distance[node]+1;
                q.push(neighbor);
            }
        }
    }
    int farthestnode = start;
    int maxdistance =0 ;
    for(int i=0;i<V;i++){
        if(distance[i]>maxdistance){
            maxdistance=distance[i];
            farthestnode=i;
        }
    }
    return {farthestnode,maxdistance};
}
int findDia(int V,vector<vector<int>>adj){
    pair<int,int>firstBFS=bfsfunction(0,V,adj);
    pair<int,int>secondBFS=bfsfunction(firstBFS.first,V,adj);
    return secondBFS.second;
}
// FIND THE LOWEST COMMON ANCESTOR OF THE NODES
void dfsfunction(int node,int parent,vector<vector<int>>&adj,vector<int>&depth,vector<int>&parentarray){
    parentarray[node]=parent;
    depth[node]=depth[parent]+1;
    for(int i=0;i<adj[node].size();i++){
        int neighbor=adj[node][i];
        if(neighbor!=parent){
            dfsfunction(neighbor,node,adj,depth,parentarray);
        }
    }
}
int findLCA(int A,int B,int V,vector<vector<int>>&adj){
    vector<int>depth(V,0);
    vector<int>parentArray(V,-1);
    dfsfunction(0,-1,adj,depth,parentArray);
    if(depth[A]<depth[B]){
        swap(A,B);
    }
    while(depth[A]>depth[B]){
        A=parentArray[A];
    }
    while(A!=B){
        A=parentArray[A];
        B=parentArray[B];
    }
    return A;
}
// GIVEN TWO NDOES A AND B FIND THE DISTANCE BETWEEN THESE NODES 
void dfsfunction(int node,int parent,vector<vector<int>>&adj,vector<int>&depth,vector<int>&parentarray){
    parentarray[node]=parent;
    depth[node]=depth[parent]+1;
    for(int i=0;i<adj[node].size();i++){
        int neighbor=adj[node][i];
        if(neighbor!=parent){
            dfsfunction(neighbor,node,adj,depth,parentarray);
        }
    }
}
int findLCA(int A,int B,vector<int>&depth,vector<int>&parentarray){
    if(depth[A]<depth[B]){
        swap(A,B);
    }
    while(depth[A]>depth[B]){
        A=parentarray[A];
    }
    while(A!=B){
        A=parentarray[A];
        B=parentarray[B];
    }
    return A;
}
int findDistance(int A,int B,int V,vector<vector<int>>adj){
    vector<int>depth(V,0);
    vector<int>parentarray(V,-1);
    dfsfunction(0,-1,adj,depth,parentarray);
    int lca=findLCA(A,B,depth,parentarray);
    return depth[A]+depth[B]-2*depth[lca];
}
// FIND THE KTH ANCESTOR OF A TREE 
void dfsfunction(int node,vector<int>&parent,vector<bool>&visited,vector<vector<int>>adj){
    visited[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            parent[neighbor]=node;
            dfsfunction(neighbor,parent,visited,adj);
        }
    }
}
int findancestor(int node,int K,vector<int>&parent){
    int current=node;
    while(K>0 && current!=-1){
        current=parent[current];
        K--;
    }
    return current;
}
int findkthAncestor(int V,int K,vector<vector<int>>adj,int vertex){
    vector<bool>visited(V,false);
    vector<int>parent(V,-1);
    parent[0]=-1;
    dfsfunction(0,parent,visited,adj);
    int ans=findancestor(vertex,K,parent);
    return ans;
}
// FIND THE MAX NODE IN ALL THE LEVELS OF A TREE 
void dfsfunction(int node,int level,vector<int>&largest,vector<bool>&visited,vector<vector<int>>adj){
    visited[node]=true;
    int n=adj[node].size();
    largest[level]=max(largest[level],node);
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsfunction(neighbor,level+1,largest,visited,adj);
        }
    }
}
vector<int>findlargest(int V,vector<vector<int>>adj){
    vector<int>largest(V,INT_MIN);
    vector<bool>visited(V,false);
    dfsfunction(0,0,largest,visited,adj);
    vector<int>result;
    for(int i=0;i<largest.size();i++){
        if(largest[i]==INT_MIN){
            result.push_back(-1);
        }else{
            result.push_back(largest[i]);
        }
    }
    return result;
}
