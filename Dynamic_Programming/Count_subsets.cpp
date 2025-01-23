#include<bits/stdc++.h>
using namespace std;
// COUNT THE NUMBER OF SUBSETS WITH GIVEN SUM 
int recursivefunction(vector<int>&arr,int sum,int n){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(arr[n-1]>sum){
        return recursivefunction(arr,sum,n-1);
    }else{
        int toinclude = recursivefunction(arr,sum-arr[n-1],n-1);
        int tonotinclude = recursivefunction(arr,sum,n-1);
        return tonotinclude+toinclude;
    }
}
int countSubsets(vector<int>&arr,int sum){
    int n=arr.size();
    return recursivefunction(arr,sum,n);

}
// TOP DOWN FUNCTION 
int topdownfunction(vector<int>&arr,int sum,int n,vector<vector<int>>&dp){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(arr[n-1] > sum){
        dp[n][sum]= topdownfunction(arr,sum,n-1,dp);
    }else{
        int toinclude = topdownfunction(arr,sum-arr[n-1],n-1,dp);
        int tonotinclude = topdownfunction(arr,sum,n-1,dp);
        dp[n][sum]=toinclude+tonotinclude;
    }
    return dp[n][sum];
}
int countSubsets(vector<int>&arr,int sum){
    vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
    return topdownfunction(arr,sum,arr.size(),dp);
}
// BOTTOM UP FUNCTION 
int countSubsets(vector<int>&arr,int sum){
    vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,0));
    for(int i=0;i<=arr.size();i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=arr.size();i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                int toInclude = dp[i-1][j-arr[i-1]];
                int tonotIncldue = dp[i-1][j];
                dp[i][j]=toInclude+tonotIncldue;
            }
        }
    }
    return dp[arr.size()][sum];
}