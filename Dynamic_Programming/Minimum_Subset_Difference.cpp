#include<bits/stdc++.h>
using namespace std;
// MINIMUM SUBSET DIFFERENCE RECURSIVE 
int recursivefunction(vector<int>&arr,int n,int current,int total){
    if(n==0){
        return abs(total-2*current);
    }else{
        int includeinfirst = recursivefunction(arr,n-1,current+arr[n-1],total);
        int includeinsecond = recursivefunction(arr,n-1,current,total);
        return min(includeinfirst,includeinsecond);
    }
}
int findmindiff(vector<int>&arr){
    int totalSum=0;
    for(int i = 0; i<arr.size() ; i++){
        totalSum+=arr[i];
    }
    return recursivefunction(arr,arr.size(),0,totalSum);
}
// TOP DOWN FUNCTION 
int topdownfunction(vector<int>&arr,int n,int current,int total,vector<vector<int>>&dp){
    if(n==0){
        return abs(total -2*current);
    }
    if(dp[n][current]!=-1){
        return dp[n][current];
    }
    int toinclude  = topdownfunction(arr,n-1,current+arr[n-1],total,dp);
    int tonotinclude = topdownfunction(arr,n-1,current,total,dp);
    dp[n][current]=min(toinclude,tonotinclude);
    return dp[n][current];
}
int findmindiff(vector<int>&arr){
    int totalsum=0;
    for(int i=0;i<arr.size();i++){
        totalsum+=arr[i];
    }
    vector<vector<int>>dp(arr.size()+1,vector<int>(totalsum+1,-1));
    return topdownfunction(arr,arr.size(),0,totalsum,dp);
}