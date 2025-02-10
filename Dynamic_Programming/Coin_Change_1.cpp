//  COIN CHANGE 1 
#include<bits/stdc++.h>
using namespace std;
// RECURSIVE FUNCTION TO FIND MINIMUM NUMBER OF COINS NEEDED TO REACH AMOUNT
int recursivefunction(vector<int>&coins,int amount,int n){
    if(amount==0){
        return 0;
    }
    if(amount < 0 || n==0 ){
        return INT_MAX;
    }
    int includeCoin = recursivefunction(coins,amount-coins[n-1],n);
    if(includeCoin!=INT_MAX){
        includeCoin++;
    }
    int excludeCoin = recursivefunction(coins,amount,n-1);
    return min(includeCoin,excludeCoin);
}
int coinChange(vector<int>&coins,int amount){
    if(amount==0){
        return 0;
    }
    int ans=recursivefunction(coins,amount,coins.size());
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}
// TOP DOWN APPROACH USING DP ARRAY TO FIND MINIMUM NUMBER OF COINS 
int topdownfunction(vector<int>&coins,int amount,int n,vector<vector<int>>&dp){
    if(amount==0){
        return 0;
    }
    if(amount<0 || n==0){
        return INT_MAX;
    }
    if(dp[n][amount]!=-1){
        return dp[n][amount];
    }
    int includeCoin = topdownfunction(coins,amount-coins[n-1],n,dp);
    if(includeCoin!=INT_MAX){
        includeCoin++;
    }
    int excludeCoin = topdownfunction(coins,amount,n-1,dp);
    dp[n][amount]=min(includeCoin,excludeCoin);
    return dp[n][amount];
}
int coinChange(vector<int>&coins,int amount){
    if(amount==0){
        return 0;
    }
    vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
    int ans=topdownfunction(coins,amount,coins.size(),dp);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}
// BOTTOM UP APPROACH TO FIND MINIMUM NUMBER OF COINS 
int coinChange(vector<int>&coins,int amount){
    vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        for(int j=0;j<coins.size();j++){
            int coin = coins[j];
            if(i-coin>=0 && dp[i-coin]!=INT_MAX){
                dp[i]=min(dp[i],dp[i-coin]);
            }
        }
    }
    if(dp[amount]!=INT_MAX){
        return dp[amount];
    }
    return -1;
}