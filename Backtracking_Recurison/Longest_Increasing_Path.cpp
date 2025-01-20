#include<bits/stdc++.h>
using namespace std;
bool isValid(int newX,int newY,vector<vector<int>>&matrix,int oldX,int oldY,vector<vector<bool>>&visited){
    bool case1 = newX>=0 && newY>=0 && newX<matrix.size() && newY < matrix[0].size();
    bool case2 = matrix[newX][newY] > matrix[oldX][oldY];
    bool case3 = visited[newX][newY];
    if(case1==true && case2==true && case3==false){
        return true;
    }
    return false;
}
int recursivefunction(int x,int y,vector<vector<bool>>&visited,vector<vector<int>>&matrix,vector<pair<int,int>>&endingPoints){
    int maxPath = 1;
    for(int i=0;i<endingPoints.size();i++){
        int checkX = endingPoints[i].first;
        int checkY = endingPoints[i].second;
        if(x==checkX && y==checkY){
            return maxPath;
        }
    }
    visited[x][y]=true;
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,-1,1};

    for(int i=0;i<4;i++){
        int newX = x+rows[i];
        int newY = y+cols[i];

        if(isValid(newX,newY,matrix,x,y,visited)==true){
            maxPath=max(maxPath,1+recursivefunction(newX,newY,visited,matrix,endingPoints));
        }
    }
    visited[x][y]=false;
    return maxPath;
}
int findLongestPath(vector<vector<int>>&matrix){
    int minNode = INT_MAX;
    int maxNode = INT_MIN;
    int startX = -1 ;
    int endX = -1 ;
    int startY = -1;
    int endY = -1;
    
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            int node = matrix[i][j];
            minNode = min(node,minNode);
            maxNode = max(node,maxNode);
        }
    }
    
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            int node = matrix[i][j];
            if(node==minNode){
                startX=i;
                startY=j;
            }
        }
    }
    vector<pair<int,int>>startingPoints;
    vector<pair<int,int>>endingPoints;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            int node=matrix[i][j];
            if(node==minNode){
                startingPoints.push_back({i,j});
            }
            if(node==maxNode){
                endingPoints.push_back({i,j});
            }
        }
    }
    vector<vector<bool>>visited(matrix.size(),vector<bool>(matrix[0].size(),false));
    int longestPath = 0;
    for(int i=0;i<startingPoints.size();i++){
        int x=startingPoints[i].first;
        int y=startingPoints[i].second;
        longestPath=max(longestPath,recursivefunction(x,y,visited,matrix,endingPoints));
    }
    return longestPath;
}