#include<bits/stdc++.h>
using namespace std;

// MATRIX CHAIN MULTIPLICATION RECURSION 


int mcmRecursion(vector<int>&arr,int i,int j){
    if(i>=j){
        return 0;
    }
    int minCost = INT_MAX;
    for(int k=i;k<j;k++){
        int leftChain = mcmRecursion(arr,i,k);
        int rightChain = mcmRecursion(arr,k+1,j);
        int product = arr[i-1]*arr[k]*arr[j];
        int total = leftChain+rightChain+product;
        minCost = min(minCost,total);   
    }
    return minCost;
}
int findAns(vector<int>&arr){
    int ans = mcmRecursion(arr,1,arr.size()-1);
    return ans;
}

// MATRIX CHAIN MULTIPLICATION TOP DOWN ( RECURSION + MEMOISATION )
int mcmTopDown(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int minCost = INT_MAX;
    for(int k=i;k<j;k++){
        int leftChain = mcmTopDown(arr,i,k,dp);
        int rightChain = mcmTopDown(arr,k+1,j,dp);
        int product = arr[i-1]*arr[k]*arr[j];
        minCost=min(minCost,leftChain+rightChain+product);
        dp[i][j]=minCost;
    }
    return dp[i][j];
}
int findAns(vector<int>&arr){
    vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
    int ans=mcmTopDown(arr,1,arr.size()-1,dp);
    return ans;
}
// MATRIX CHAIN MULITPLICATION BOTTOM UP 
int findAns(vector<int>&arr){
    vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,0));
    for(int l=2;l<arr.size();l++){
        for(int i=1;i<arr.size()-l+1;i++){
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int leftChain = dp[i][k];
                int rightChain = dp[k+1][j];
                int product = arr[i-1]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j],leftChain+rightChain+product);
            }
        }
    }
    return dp[1][arr.size()-1];
}