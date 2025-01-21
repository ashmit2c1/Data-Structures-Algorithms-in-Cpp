#include<bits/stdc++.h>
using namespace std;
// CALCULATE THE LARGEST FRIEND CIRCCLE 
void dfsfunction(int node,vector<bool>&visited,vector<int>adj[],int&count){
    visited[node]=true;
    int n=adj[node].size();
    count++;
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsfunction(neighbor,visited,adj,count);
        }
    }
}
int findLargestGroup(int N,vector<pair<int,int>>&connections){
    vector<int>adj[N];
    for(int i=0;i<connections.size();i++){
        int u=connections[i].first;
        int v=connections[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int maxcount=0;
    int count=0;
    vector<bool>visited(N,false);
    for(int i=0;i<N;i++){
        if(visited[i]==false){
            dfsfunction(i,visited,adj,count);
            maxcount=max(maxcount,count);
            count=0;
        }
    }
    return maxcount;
}
// CALCULATE THE LARGEST FRIEND CIRCLE OPTIMISED WAY 
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
    
}
int findLargestGroup(int N,vector<pair<int,int>>&connections){
    vector<int>parent(N);
    vector<int>setsize(N);

    for(int i=0;i<connections.size();i++){
        int u=connections[i].first;
        int v=connections[i].second;
        unionfunction(u,v,parent,setsize);
    }
    int maxsetsize=INT_MIN;
    for(int i=0;i<setsize.size();i++){
        int size=setsize[i];
        maxsetsize=max(maxsetsize,size);
    }
    return maxsetsize;
}
