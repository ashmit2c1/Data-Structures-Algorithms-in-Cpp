#include<bits/stdc++.h>
using namespace std;
// GIVEN QUERIES FIND IF THE COMPONENTS ARE CONNECTED
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
    int parentU = findParent(u,parent);
    int parentV = findParent(v,parent);
    if(parentU!=parentV){
        if(setsize[parentV]<setsize[parentU]){
            swap(parentU,parentV);
        }
        parent[parentV]=parentU;
        setsize[parentU]+=setsize[parentV];
    }
}
vector<bool>checkIfConnected(int N,vector<pair<int,int>>&connections,vector<pair<int,int>>&queries){
    vector<bool>ans(queries.size(),false);
    vector<int>parent(N);
    vector<int>setsize(N);
    for(int i=0;i<N;i++){
        parent[i]=i;
        setsize[i]=1;
    }
    for(int i=0;i<connections.size();i++){
        int u=connections[i].first;
        int v=connections[i].second;
        unionfunction(u,v,parent,setsize);
    }
    for(int i=0;i<queries.size();i++){
        int u = queries[i].first;
        int v = queries[i].second;
        if(findParent(u,parent)==findParent(v,parent)){
            ans[i]=true;
        }
    }
    return ans;
}