#include<bits/stdc++.h>
using namespace std;


// EGG DROPPING PROBLEM RECURSIVE CODE 
int eggDropRecursive(int n,int k){
    if(k==1){
        return n;
    }
    if(n==1){
        return 1; 
    }
    if(n==0){
        return 0;
    }
    int minAttempts= INT_MAX;
    for(int i=1;i<=n;i++){
        int eggbreaks = eggDropRecursive(i-1,k-1);
        int eggDoesNotBreak = eggDropRecursive(n-i,k);
        int worstCase = max(eggbreaks,eggDoesNotBreak);
        minAttempts=min(minAttempts,worstCase+1);
    }
    return minAttempts;
}
// EGG DROPPING TOP DOWN SOLUTION
int eggDropTopDown(int n,int k,vector<vector<int>>&dp){
    if(k==1){
        return n;
    }
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    int minAttempts=INT_MAX;
    for(int i=1;i<=n;i++){
        int eggBreaks = eggDropTopDown(i-1,k-1,dp);
        int eggDoesNotBreak = eggDropTopDown(n-i,k,dp);
        int worstCase = max(eggBreaks,eggDoesNotBreak);
        minAttempts=min(minAttempts,worstCase+1);
        dp[n][k]=minAttempts;
    }
    dp[n][k]=minAttempts;
    return dp[n][k];
}
// EGG DROPPING PROBLEM BOTTOM UP 
int eggDropBottomUp(int n,int k){
    vector<vector<int>>dp(n,vector<int>(k,0));
    for(int i=1;i<=k;i++){
        dp[1][i]=1;
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        dp[1][i]=i;
    }
    for(int i=2;i<=k;i++){
        for(int j=2;j<=n;j++){
            dp[i][j]=INT_MAX;
            for(int x=1;x<=j;x++){
                int attempts=max(dp[i-1][x-1], dp[i][j-x]);
                dp[i][j] = min(dp[i][j],attempts+1);
            }
        }
    }
    return dp[n][k];
}
