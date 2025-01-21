#include<bits/stdc++.h>
using namespace std;
// LONGEST INCREASING PATH RECURSIVE FUNCTION 
bool isValid(int x,int y,vector<vector<int>>&matrix){
    if(x>=0 && y>=0 && x<matrix.size() && y<matrix[0].size()){
        return true;
    }
    return false;
}
int recursivefunction(int x,int y,vector<vector<int>>&matrix){
    int maxpath = 1;
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,-1,1};
    for(int i=0;i<4;i++){
        int newX = x + rows[i];
        int newY = y + cols[i];
        if(isValid(newX,newY,matrix)==true && matrix[newX][newY] > matrix[x][y]){
            maxpath = max(maxpath,1+recursivefunction(newX,newY,matrix));
        }
    }
    return maxpath;
}
int findLongestPath(vector<vector<int>>&matrix){
    int longestpath = INT_MIN;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            longestpath = max(longestpath,recursivefunction(i,j,matrix));
        }
    }
    return longestpath;
}
// LONGEST INCREASING PATH TOP DOWN APPROACH 
int topdownfunction(int i,int j,vector<vector<int>>matrix,vector<vector<int>>&dp){
    int maxpath = 1;
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,-1,1};
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    for(int i=0;i<4;i++){
        int newX = i + rows[i];
        int newY = j + cols[i];
        if(isValid(newX,newY,matrix)==true && matrix[newX][newY] > matrix[i][j]){
            maxpath = max(maxpath,1+topdownfunction(newX,newY,matrix,dp));
        }
    }
    dp[i][j]=maxpath;
    return dp[i][j];
}
int findLongestPath(vector<vector<int>>&matrix){
    vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
    int longestpath = INT_MIN;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            longestpath=max(longestpath,topdownfunction(i,j,matrix,dp));
        }
    }
    return longestpath;
}