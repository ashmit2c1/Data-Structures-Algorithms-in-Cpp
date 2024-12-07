#include<bits/stdc++.h>
using namespace std;
// RECURSIVE CODE
int findMinOpsHelper(string s1,string s2,int m,int n){
    if(m==0){
        return n;
    }
    if(n==0){
        return m;
    }
    if(s1[m-1]==s2[n-1]){
        return findMinOpsHelper(s1,s2,m-1,n-1);
    }
    else{
        int replace=findMinOpsHelper(s1,s2,m-1,n-1);
        int insert=findMinOpsHelper(s1,s2,m,n-1);
        int del=findMinOpsHelper(s1,s2,m-1,n);
        return 1+min({replace,insert,del});
    }
}
int findMinOps(string s1,string s2){
    int ans=findMinOpsHelper(s1,s2,s1.size(),s2.size());
    return ans;
}
// TOP DOWN CODE
int findMinOpsTopDown(string s1,string s2,int m,int n,vector<vector<int>>&dp){
    if(n==0){
        return m;
    }
    if(m==0){
        return n;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(s1[m-1]==s2[n-1]){
        dp[n][m]=findMinOpsTopDown(s1,s2,m-1,n-1,dp);
    }
    else{
        int replace = findMinOpsTopDown(s1,s2,m-1,n-1,dp);
        int del=findMinOpsTopDown(s1,s2,m-1,n,dp);
        int insert=findMinOpsTopDown(s1,s2,m,n-1,dp);
        dp[n][m]=1+min({replace,del,insert});
    }
    return dp[n][m];
}
int findMinOps(string s1,string s2){
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    int ans=findMinOpsTopDown(s1,s2,s1.size(),s2.size(),dp);
    return ans;
}
// BOTTOM UP CODE 
int findMinOps(string s1,string s2){
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    int m=s1.size();int n=s2.size();
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                dp[i][j]=j;
            }
            if(j==0){
                dp[i][j]=i;
            }
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int replace = dp[i-1][j-1];
                int insert = dp[i-1][j];
                int del=dp[i][j-1];
                dp[i][j]=1+min({replace,insert,del});
            }
        }
    }
    return dp[n][m];
}