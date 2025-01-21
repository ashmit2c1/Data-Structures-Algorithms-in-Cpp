#include<bits/stdc++.h>
using namespace std;
// COUNT THE NUMBER OF CONNECTED COMPONENTS
void dfsfunction(int node,vector<bool>&visited,vector<vector<int>>adj){
    visited[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsfunction(neighbor,visited,adj);
        }
    }
}
int countConnected(int N,vector<pair<int,int>>&connections){
    vector<vector<int>>adj(N);
    for(int i=0;i<connections.size();i++){
        int u=connections[i].first;
        int v=connections[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(N,false);
    int count=0;
    for(int i=0;i<N;i++){
        if(visited[i]==false){
            count++;
            dfsfunction(i,visited,adj);
        }
    }
    return count;
}
// COUNT THE NUMBER OF CONNECTED COMPONENTS 
int findParent(int element,vector<int>&parent){
    if(parent[element]==element){
        return element;
    }else{
        int leader_element = findParent(parent[element],parent);
        parent[element]=leader_element;
        return leader_element;
    }
}
void unionfunction(int u,int v,vector<int>&parent,vector<int>&setsize){
    int parentU=findParent(u,parent);
    int parentV=findParent(v,parent);
    if(parentU!=parentV){
        if(setsize[parentV] < setsize[parentU]){
            swap(parentU,parentV);
        }
        parent[parentV]=parentU;
        setsize[parentU]+=setsize[parentV];
    }
}
int countConnected(int N,vector<pair<int,int>>&connections){
    vector<int>parent(N);
    vector<int>setsize(N);
    for(int i=0;i<N;i++){
        parent[i]=i;
        setsize[i]=1;
    }
    for(int i=0;i<connections.size();i++){
        int u = connections[i].first;
        int v = connections[i].second;
        unionfunction(u,v,parent,setsize);
    }
    int count=0;
    for(int i=0;i<parent.size();i++){
        if(parent[i]==i){
            count++;
        }
    }
    return count;
}