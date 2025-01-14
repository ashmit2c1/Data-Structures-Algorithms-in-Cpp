#include<bits/stdc++.h>
using namespace std;

// UNQIUE PATHS 1 RECURSION 
int uniquePaths1Recursion(int i,int j,int r,int c){
    if(i>=r || j>=c){
        return 0;
    }
    if(i==r-1 && j==c-1){
        return 1;
    }
    int goingDown = uniquePaths1Recursion(i+1,j,r,c);
    int goingRight = uniquePaths1Recursion(i,j+1,r,c);
    return goingDown + goingRight;
}
int unqiuePaths1(vector<vector<int>>&matrix){
    int ans=uniquePaths1Recursion(0,0,matrix.size(),matrix[0].size());
    return ans;
}
// UNQIUE PATHS 1 TOP DOWN 
int uniquePaths1TopDown(int i,int j,int r,int c,vector<vector<int>>&dp){
    if(i>=r || j>=c){return 0;}
    if(i==r-1 && j==c-1){return 1;}
    if(dp[i][j]!=-1){return dp[i][j];}
    int goingRight = uniquePaths1TopDown(i,j+1,r,c,dp);
    int goingDown = uniquePaths1TopDown(i+1,j,r,c,dp);
    dp[i][j]=goingRight + goingDown;
    return dp[i][j];
}
int uniquePaths1(int r,int c){
    vector<vector<int>>dp(r+1,vector<int>(c+1,-1));
    int ans=uniquePaths1TopDown(0,0,r,c,dp);
    return ans;
}
// UNIQUE PATHS 1 BOTTOM UP 
int uniquePaths1(int r,int c){
    vector<vector<int>>dp(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        dp[i][0]=1;
    }
    for(int i=0;i<c;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            dp[i][j]=dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[r-1][c-1];
}