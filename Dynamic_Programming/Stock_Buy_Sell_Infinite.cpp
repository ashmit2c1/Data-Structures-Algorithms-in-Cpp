#include<bits/stdc++.h>
using namespace std;

// STOCK BUY AND SELL WITH INFINITE TRANSACTIONS 
int findProfitRecursion(vector<int>&arr,int index,bool canSell){
    if(index==arr.size()){
        return 0;
    }
    if(canSell==true){
        int sellStock = arr[index] + findProfitRecursion(arr,index+1,false);
        int notSellStock = findProfitRecursion(arr,index+1,true);
        return max(sellStock,notSellStock);
    }else{
        int buyStock = findProfitRecursion(arr,index+1,true)-arr[index];
        int notBuyStock = findProfitRecursion(arr,index+1,true);
        return max(buyStock,notBuyStock);
    }
    
}
int findProfit(vector<int>&arr){
    int ans=findProfitRecursion(arr,0,false);
    return ans;
}
// STOCK BUY AND SELL WITH INFINTITE TRANSACTIONS TOP DOWN 
int findProfitTopDown(vector<int>&arr,int index,bool canSell,vector<vector<int>>&dp){
    if(index==arr.size()){
        return 0;
    }
    if(dp[index][canSell]!=-1){
        return dp[index][canSell];
    }
    if(canSell==true){
        int sellStock = arr[index] + findProfitTopDown(arr,index+1,false,dp);
        int notSellStock = findProfitTopDown(arr,index+1,true,dp);
        dp[index][canSell]=max(sellStock,notSellStock);
    }else{
        int buyStock = findProfitTopDown(arr,index+1,true,dp)-arr[index];
        int notBuyStock = findProfitTopDown(arr,index+1,false,dp);
        dp[index][canSell]=max(buyStock,notBuyStock);
    }
    return dp[index][canSell];
}
int findProfit(vector<int>&arr){
    vector<vector<int>>dp(arr.size()+1,vector<int>(2,-1));
    int ans=findProfitTopDown(arr,0,false,dp);
    return ans;
}