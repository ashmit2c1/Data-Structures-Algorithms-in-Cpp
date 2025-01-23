#include<bits/stdc++.h>
using namespace std;

// RECURSIVE FUNCTION 
bool recursivefunction(vector<int>&arr,int n,int target){
    if(target==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(arr[n-1]>target){
        return recursivefunction(arr,n-1,target);
    }else{
        bool toInclude = recursivefunction(arr,n-1,target-arr[n-1]);
        bool toNotInclude = recursivefunction(arr,n-1,target);
        if(toInclude==true || toNotInclude==true){
            return true;
        }else{
            return false;
        }
    }
}
bool isSubset(vector<int>&arr,int target){
    bool ans = recursivefunction(arr,arr.size(),target);
    return ans;
}
// TOP DOWN FUNCTION 
bool topdownfunction(vector<int>&arr,int n,int target,vector<vector<int>>&dp){
    if(target==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    if(arr[n-1]>target){
        dp[n][target]=topdownfunction(arr,n-1,target,dp);
    }else{
        bool toinclude = topdownfunction(arr,n-1,target-arr[n-1],dp);
        bool tonotinclude = topdownfunction(arr,n-1,target,dp);
        dp[n][target]=toinclude||tonotinclude;
    }
    return dp[n][target];
}
bool isSubset(vector<int>&arr,int target){
    vector<vector<int>>dp(arr.size()+1,vector<int>(target+1,-1));
    bool ans = topdownfunction(arr,arr.size(),target,dp);
    return ans;
}
// BOTTOM UP FUNCTION 
bool isSubset(vector<int>&arr,int target){
    int n=arr.size();
    vector<vector<bool>>dp(arr.size()+1,vector<bool>(target+1,false));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                bool toinclude = dp[i-1][j-arr[i-1]];
                bool tonotincldue = dp[i-1][j];
                dp[i][j] = toinclude || tonotincldue;
            }
        }
    }
    return dp[arr.size()][target];
}